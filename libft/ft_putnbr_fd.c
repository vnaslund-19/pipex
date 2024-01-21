/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:30:48 by vnaslund          #+#    #+#             */
/*   Updated: 2023/09/13 16:37:42 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (ln < 0)
	{
		ln = -ln;
		ft_putchar_fd('-', fd);
	}
	if (ln > 9)
	{
		ft_putnbr_fd(ln / 10, fd);
	}
	ft_putchar_fd(ln % 10 + 48, fd);
}
