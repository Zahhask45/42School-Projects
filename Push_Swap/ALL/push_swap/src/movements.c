/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:01:07 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/07 18:59:52 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapback.h"

int	can_pb(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a->size)
		return (0);
	if (stack_b->size < 2)
		return (1);
	else if (stack_a->value[0] > stack_b->value[0])
	{
		if (stack_a->value[0] < stack_b->value[stack_b->size - 1]
			&& stack_b->value[0] < stack_b->value[stack_b->size - 1])
			return (1);
		else if (stack_a->value[0] > stack_b->value[stack_b->size - 1]
			&& stack_b->value[0] > stack_b->value[stack_b->size - 1])
			return (1);
	}
	else if (stack_a->value[0] < stack_b->value[stack_b->size - 1]
		&& stack_b->value[stack_b->size - 1] < stack_b->value[0])
		return (1);
	return (0);
}

size_t	closer_pos_to_inf(int nb, t_list *stack)
{
	size_t	pos;

	pos = 0;
	if (nb > stack->value[0] && nb < stack->value[stack->size - 1])
		return (pos);
	while (pos < stack->size && nb > stack->value[pos])
		pos++;
	if (pos != stack->size)
	{
		while (pos < stack->size - 1 && nb < stack->value[pos])
			pos++;
		if (pos == stack->size - 1 && stack->value[pos] > nb)
			pos = stack->size;
	}
	if (pos == stack->size)
	{
		pos = 1;
		while (pos < stack->size && stack->value[pos - 1] > stack->value[pos])
			pos++;
	}
	if (pos == stack->size)
		pos = 0;
	return (pos);
}

size_t	less_mvt_at_begin(size_t minimal_mvt, size_t *min_mvt, t_list *stack_a,
		t_list *stack_b)
{
	size_t	i;
	size_t	min;
	size_t	tmp[2];

	if (minimal_mvt > stack_b->size / 2)
		minimal_mvt = stack_b->size - minimal_mvt;
	min = minimal_mvt + 1;
	i = 0;
	while (++i < stack_a->size && i < minimal_mvt)
	{
		tmp[0] = closer_pos_to_inf(stack_a->value[i], stack_b);
		tmp[1] = stack_b->size - tmp[0];
		if ((tmp[0] > stack_b->size / 2 && i + tmp[1] < min) || (tmp[0] >= i
				&& tmp[0] < min) || (tmp[0] < i && i < min))
			*min_mvt = tmp[0];
		if (tmp[0] > stack_b->size / 2 && i + tmp[1] < min)
			min = i + tmp[1];
		else if (tmp[0] >= i && tmp[0] < min)
			min = tmp[0];
		else if (tmp[0] < i && i < min)
			min = i;
	}
	return (min);
}

size_t	less_mvt_at_end(size_t minimal_mvt, size_t *min_mvt, t_list *s_a,
		t_list *s_b)
{
	size_t	i;
	size_t	m;
	size_t	t[2];

	if (minimal_mvt > s_b->size / 2)
		minimal_mvt = s_b->size - minimal_mvt;
	m = minimal_mvt + 1;
	i = s_a->size;
	while (--i > 0 && (s_a->size - i) < minimal_mvt)
	{
		t[0] = closer_pos_to_inf(s_a->value[i], s_b);
		t[1] = s_b->size - t[0];
		if ((t[0] > s_b->size / 2 && t[1] >= (s_a->size - i) && t[1] < m)
			|| (t[0] > s_b->size / 2 && t[1] < (s_a->size - i)
				&& (s_a->size - i) < m) || ((s_a->size - i) + t[0] < m))
			*min_mvt = t[0];
		if (t[0] > s_b->size / 2 && t[1] >= (s_a->size - i) && t[1] < m)
			m = t[1];
		else if (t[0] > s_b->size / 2 && t[1] < (s_a->size - i)
			&& (s_a->size - i) < m)
			m = (s_a->size - i);
		else if ((s_a->size - i) + t[0] < m)
			m = (s_a->size - i) + t[0];
	}
	return (m);
}
