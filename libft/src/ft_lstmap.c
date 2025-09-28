/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:57:39 by jodos-sa          #+#    #+#             */
/*   Updated: 2022/11/11 16:28:41 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_node;
	t_list	*current_node;

	if (!lst || !f || !del)
		return (NULL);
	head_node = ft_lstnew(f(lst->content));
	if (head_node == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		current_node = ft_lstnew(f(lst->content));
		if (current_node == NULL)
		{
			ft_lstclear(&head_node, del);
			return (NULL);
		}
		ft_lstadd_back(&head_node, current_node);
		lst = lst->next;
	}
	return (head_node);
}
