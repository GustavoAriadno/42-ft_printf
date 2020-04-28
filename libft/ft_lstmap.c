/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:46:08 by gariadno          #+#    #+#             */
/*   Updated: 2020/01/31 15:06:47 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	t_list	*first;

	if (!lst)
		return (NULL);
	if (!(new = ft_lstnew(f(lst->content))))
		return (NULL);
	first = new;
	lst = lst->next;
	while (lst)
	{
		if (!(temp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		new->next = temp;
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
