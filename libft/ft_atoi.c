/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:30:11 by vnaslund          #+#    #+#             */
/*   Updated: 2023/09/12 14:52:31 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str1[] = "				  +12345abc333";

    printf("my: %d\n", ft_atoi(str1));
	printf("og: %d\n", atoi(str1));

    return 0;
}
*/
