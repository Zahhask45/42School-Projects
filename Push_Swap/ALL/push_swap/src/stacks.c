/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:40:14 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/03/19 17:40:16 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapback.h"

int	order_stack(t_list *stack, int order)
{
	size_t	i;

	i = 0;
	if (stack->size == 0)
		return (1);
	while (i < stack->size - 1)
	{
		if ((order == ASC && stack->value[i] >= stack->value[i + 1])
			|| (order == DESC && stack->value[i] <= stack->value[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	stack_contains(t_list *stack, int num)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->value[i++] == num)
			return (1);
	}
	return (0);
}

t_list	*new_empty_stack(size_t max_size)
{
	t_list	*stack;

	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	stack->value = malloc(sizeof(int) * max_size);
	if (!stack->value)
	{
		free(stack);
		return (NULL);
	}
	stack->max_size = max_size;
	stack->size = 0;
	return (stack);
}
