/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:32:02 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/03/25 16:32:04 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapback.h"

void	calcul_align_a(size_t *pos, size_t *mvt, t_list *stack_a,
t_list *stack_b)
{
	*pos = 0;
	*mvt = 0;
	if (order_stack(stack_a, ASC))
	{
		while (*pos < stack_a->size - 1
			&& stack_a->value[*pos] < stack_a->value[*pos + 1])
			(*pos)++;
		if (*pos > stack_b->size / 2)
			*mvt = stack_a->size - (*pos + 1);
		else
			*mvt = *pos + 1;
	}
}

void	calcul_align_b(size_t *pos, size_t *mvt, t_list *stack_b)
{
	*pos = 0;
	*mvt = 0;
	if (stack_b->size == 0)
		return ;
	if (order_stack(stack_b, DESC))
	{
		while (*pos < stack_b->size - 1
			&& stack_b->value[*pos] > stack_b->value[*pos + 1])
			(*pos)++;
		if (*pos > stack_b->size / 2)
			*mvt = stack_b->size - (*pos + 1);
		else
			*mvt = *pos + 1;
	}
}

int	align_stack_a(t_all *prg)
{
	size_t		i;
	size_t		num;
	t_instruct	*temp;

	calcul_align_a(&i, &num, &prg->stack_a, &prg->stack_b);
	while (num--)
	{
		if (i > prg->stack_a.size / 2)
			temp = add_instr(&prg->last_inst, "rra");
		else
			temp = add_instr(&prg->last_inst, "ra");
		if (!temp)
			return (1);
		pick_instruction(temp, &prg->stack_a, &prg->stack_b, prg->debug);
	}
	return (0);
}

int	align_stack_b(t_all *prg)
{
	size_t		i;
	size_t		num;
	t_instruct	*temp;

	calcul_align_b(&i, &num, &prg->stack_b);
	while (num--)
	{
		if (i > prg->stack_b.size / 2)
			temp = add_instr(&prg->last_inst, "rrb");
		else
			temp = add_instr(&prg->last_inst, "rb");
		if (!temp)
			return (1);
		pick_instruction(temp, &prg->stack_a, &prg->stack_b, prg->debug);
	}
	return (0);
}
