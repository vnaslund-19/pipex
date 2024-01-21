/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:14:19 by vnaslund          #+#    #+#             */
/*   Updated: 2023/09/11 14:15:07 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char a = '9';
	printf("%d\n", ft_isdigit(0));
	printf("%d", isdigit(0));
}
*/
