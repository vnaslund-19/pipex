/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:05:47 by vnaslund          #+#    #+#             */
/*   Updated: 2023/09/14 12:44:32 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*mem;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		mem = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = mem;
	}
	*lst = NULL;
}
