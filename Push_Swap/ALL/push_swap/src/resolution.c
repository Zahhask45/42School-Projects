/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:00:54 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/16 14:05:30 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapback.h"

int	create_states_resolution(t_state **states)
{
	int			i;
	t_instruct	*temp;
	t_state		*new;

	i = -DEPTH - 1;
	while (++i < DEPTH)
	{
		temp = NULL;
		if (!i)
			new = new_state_instruction(states, *states, "pb");
		else if (i < 0)
		{
			new = new_state_instruction(states, *states, "ra");
			temp = add_x_instructions(&new->instructions, "ra", DEPTH + i);
		}
		else if (i > 0)
		{
			new = new_state_instruction(states, *states, "rra");
			temp = add_x_instructions(&new->instructions, "rra", i - 1);
		}
		pick_instruction(temp, new->stack_a, new->stack_b, 0);
		if (!new || (!temp && i && i != -DEPTH && i != 1))
			return (1);
	}
	return (0);
}

t_instruct	*rotate_a(t_state *state, size_t min[2], size_t min_mvt[2])
{
	t_instruct	*instr;

	if (min[0] <= min[1] && min_mvt[0] <= state->stack_b->size / 2)
		instr = add_instr(&state->instructions, "rr");
	else if (min[0] < min[1] && min_mvt[0] > state->stack_b->size / 2)
		instr = add_instr(&state->instructions, "ra");
	else if (min_mvt[1] > state->stack_b->size / 2)
		instr = add_instr(&state->instructions, "rrr");
	else
		instr = add_instr(&state->instructions, "rra");
	return (instr);
}

t_instruct	*another_rotate(t_state *state)
{
	t_instruct	*instr;
	size_t		mvt[2];
	size_t		min[2];
	size_t		min_mvt[2];

	mvt[0] = closer_pos_to_inf(state->stack_a->value[0], state->stack_b);
	min[0] = less_mvt_at_begin(mvt[0], &min_mvt[0], state->stack_a,
			state->stack_b);
	min[1] = less_mvt_at_end(mvt[0], &min_mvt[1], state->stack_a,
			state->stack_b);
	if (mvt[0] > state->stack_b->size / 2)
		mvt[1] = state->stack_b->size - mvt[0];
	else
		mvt[1] = mvt[0];
	if (state->stack_a->size > 1 && (min[0] <= mvt[1] || min[1] <= mvt[1]))
		instr = rotate_a(state, min, min_mvt);
	else if (mvt[0] > state->stack_b->size / 2)
		instr = add_instr(&state->instructions, "rrb");
	else
		instr = add_instr(&state->instructions, "rb");
	return (instr);
}

int	large_resolve(t_state *states)
{
	t_instruct	*tmp;
	t_state		*tmp_state;

	tmp_state = states->next;
	while (tmp_state)
	{
		while (tmp_state->stack_a->size > 5)
		{
			if (can_pb(tmp_state->stack_a, tmp_state->stack_b))
				tmp = add_instr(&tmp_state->instructions, "pb");
			else
				tmp = another_rotate(tmp_state);
			if (!tmp)
			{
				free_states(states);
				return (1);
			}
			pick_instruction(tmp, tmp_state->stack_a, tmp_state->stack_b, 0);
		}
		tmp_state = tmp_state->next;
	}
	return (0);
}
