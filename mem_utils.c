/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:11:17 by vnaslund          #+#    #+#             */
/*   Updated: 2023/10/17 12:45:30 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_freearray(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free (array);
}

int	arg_error(void)
{
	write(1, "Wrong number of args", 21);
	exit(1);
}
