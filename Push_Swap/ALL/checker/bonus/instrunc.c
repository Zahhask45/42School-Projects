/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:37:25 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/15 16:49:14 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate(t_list *stack)
{
	size_t	i;
	int		temp;

	if (stack->size > 1)
	{
		temp = stack->value[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->value[i] = stack->value[i - 1];
			i--;
		}
		stack->value[0] = temp;
	}
}

void	rotate(t_list *stack)
{
	size_t	i;
	int		temp;

	if (stack->size > 1)
	{
		temp = stack->value[0];
		i = 0;
		while (i < stack->size - 1)
		{
			stack->value[i] = stack->value[i + 1];
			i++;
		}
		stack->value[stack->size - 1] = temp;
	}
}

void	push(t_list *to, t_list *from)
{
	if (from->size > 0)
	{
		to->size++;
		reverse_rotate(to);
		to->value[0] = from->value[0];
		rotate(from);
		from->size--;
	}
}

void	swap(t_list *stack)
{
	int	temp;

	if (stack->size > 1)
	{
		temp = stack->value[0];
		stack->value[0] = stack->value[1];
		stack->value[1] = temp;
	}
}
