/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:34:36 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/17 13:13:45 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	pid;
	int	fd[2];

	if (argc != 5)
		return (arg_error());
	if (pipe(fd) == -1)
	{
		perror("Pipe error");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Fork error");
		exit(1);
	}
	if (pid == 0)
		child_process(argv, env, fd);
	else
	{
		wait(NULL);
		parent_process(argv, env, fd);
	}
	return (0);
}

void	child_process(char **av, char **env, int fd[2])
{
	int	infile;

	close(fd[0]);
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
	{
		perror("Infile open error");
		exit(1);
	}
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("Child: Error duplicating STDIN");
		exit(1);
	}
	close(infile);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("Child: Error duplicating STDOUT");
		exit(1);
	}
	close(fd[1]);
	exec_cmd(av[2], env);
}

void	parent_process(char **av, char **env, int fd[2])
{
	int	outfile;

	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("Parent: Error duplicating STDIN");
		exit(1);
	}
	close(fd[0]);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("Outfile open error");
		exit(1);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		perror("Parent: Error duplicating STDOUT");
		exit(1);
	}
	close(outfile);
	exec_cmd(av[3], env);
}

void	exec_cmd(char *str_cmd, char **env)
{
	char	**cmd_wflags;
	char	*path;

	cmd_wflags = ft_split(str_cmd, ' ');
	if (cmd_wflags == NULL)
	{
		perror("Cmd error");
		exit(1);
	}
	path = get_path(cmd_wflags[0], env);
	if (path == NULL)
	{
		ft_freearray(cmd_wflags);
		perror("Cmd not found");
		exit(1);
	}
	if (execve(path, cmd_wflags, env) == -1)
	{
		free(path);
		ft_freearray(cmd_wflags);
		perror("Execve error");
		exit(1);
	}
}

char	*get_path(char *cmd, char **env)
{
	char	**possible_paths;
	int		i;
	char	*path;
	char	*temp;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
	}
	possible_paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (possible_paths[++i])
	{
		temp = ft_strjoin(possible_paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
	}
	ft_freearray(possible_paths);
	return (path);
}
/*
          +------------------------+
          |                        |
          |      Child Process     |
          |                        |
          +------------------------+
          |     infile = STDIN     |  
          | write to STDOUT (fd[1])|------------------+
          +------------------------+                  |
                                                      |
                                                      V
          +------------------------+             +--------+ fd[1] = write
          |                        |             |  PIPE  |
          |    Parent Process      |             +--------+ fd[0] = read
          |                        |                  |
          +------------------------+                  |
          | read from STDIN (fd[0])|<-----------------+
          |write to STDOUT(outfile)|
          +------------------------+
*/