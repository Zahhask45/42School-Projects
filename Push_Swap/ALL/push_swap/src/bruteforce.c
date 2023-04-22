/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:29:15 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/03/25 16:29:17 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapback.h"

int	check_bruteforce_solution(t_state *states, t_state **result)
{
	while (states && !(*result))
	{
		if (!states->stack_b->size && !order_stack(states->stack_a, ASC))
		{
			if (!add_state(result, states))
			{
				free_states(states);
				return (1);
			}
		}
		states = states->next;
	}
	return (0);
}

t_state	*pick_bruteforce(t_state *states, size_t pos[2], t_list *stack_b)
{
	t_state	*result;
	t_state	*new_states;
	t_state	*temp;

	result = NULL;
	while (!result)
	{
		new_states = NULL;
		temp = states;
		while (temp)
		{
			if (bruteforce_choice_a(&new_states, temp, pos, stack_b))
			{
				free_states(new_states);
				return (NULL);
			}
			temp = temp->next;
		}
		free_states(states);
		states = new_states;
		if (check_bruteforce_solution(states, &result))
			return (NULL);
	}
	free_states(states);
	return (result);
}

int	bruteforce_order_a(t_all *prg)
{
	size_t	pos[2];
	t_state	*result;
	t_state	*states;

	calcul_align_b(&pos[0], &pos[1], &prg->stack_b);
	states = new_empty_state(&prg->stack_a, NULL, prg->stack_a.max_size);
	if (!states)
		return (1);
	result = pick_bruteforce(states, pos, &prg->stack_b);
	if (!result)
	{
		free_states(states);
		return (1);
	}
	pick_instruction(result->instructions, &prg->stack_a, &prg->stack_b,
		prg->debug);
	if (!copy_and_concat_instructions(&prg->last_inst, result->instructions))
	{
		free_states(result);
		return (1);
	}
	free_states(result);
	return (0);
}
