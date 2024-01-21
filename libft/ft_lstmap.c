/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:21:56 by vnaslund          #+#    #+#             */
/*   Updated: 2023/09/15 18:15:55 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	*destroy(void (*del)(void *), t_list *start, void *data)
{
	del(data);
	ft_lstclear(&start, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;
	void	*data;

	if (!lst || !f || !del)
		return (NULL);
	data = f(lst->content);
	start = ft_lstnew(data);
	if (!start)
		return (destroy(del, start, data));
	new = start;
	lst = lst->next;
	while (lst)
	{
		data = f(lst->content);
		new->next = ft_lstnew(data);
		if (!new->next)
			return (destroy(del, start, data));
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
