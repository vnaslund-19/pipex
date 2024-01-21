/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:01:05 by vnaslund          #+#    #+#             */
/*   Updated: 2023/09/11 14:05:01 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char a = '%';
	printf("%d\n", ft_isalnum(a));
	printf("%d", isalnum(a));
}
*/
