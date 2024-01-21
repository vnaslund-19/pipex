/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:10:36 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/17 12:45:23 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>

void	child_process(char **av, char **env, int fd[2]);
void	parent_process(char **av, char **env, int fd[2]);
void	exec_cmd(char *str_cmd, char **env);
char	*get_path(char *cmd, char **env);
void	ft_freearray(char **array);
int		arg_error(void);

#endif
