/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:47:56 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/03/05 16:47:58 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapback.h"

t_list	*copy_stack(t_list *stack)
{
	size_t	i;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = malloc(sizeof(int) * stack->max_size);
	if (!new->value)
		return (NULL);
	i = 0;
	while (i < stack->size)
	{
		new->value[i] = stack->value[i];
		i++;
	}
	new->size = stack->size;
	new->max_size = stack->max_size;
	return (new);
}
