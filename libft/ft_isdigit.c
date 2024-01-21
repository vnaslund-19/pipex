/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:18:37 by vnaslund          #+#    #+#             */
/*   Updated: 2023/09/11 12:24:30 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
