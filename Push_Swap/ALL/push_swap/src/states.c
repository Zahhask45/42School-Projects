/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:56:56 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/03/25 15:56:58 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapback.h"

void	check(t_state *state, t_list *stack, size_t max_size)
{
	if (!stack)
	{
		state->stack_b = new_empty_stack(max_size);
		if (!state->stack_b)
		{
			free_stack(state->stack_a);
			free(state);
			return ;
		}
	}
	else
		state->stack_b = copy_stack(stack);
}

t_state	*new_state_instruction(t_state **states, t_state *old_state, char *line)
{
	t_state		*state;
	t_instruct	*instr;

	state = add_state(states, old_state);
	if (!state)
		return (NULL);
	instr = add_instr(&state->instructions, line);
	if (!instr)
	{
		free_states(state);
		return (NULL);
	}
	state->last_instr = instr;
	pick_instruction(instr, state->stack_a, state->stack_b, 0);
	return (state);
}

void	free_states(t_state *states)
{
	t_state	*temp;
	t_state	*next;

	temp = states;
	while (temp)
	{
		next = temp->next;
		free_stack(temp->stack_a);
		free_stack(temp->stack_b);
		free_instr(temp->instructions);
		free(temp);
		temp = next;
	}
}

t_state	*add_state(t_state **states, t_state *state_from)
{
	t_state	*temp;
	t_state	*new;

	new = malloc(sizeof(t_state));
	if (!new)
		return (NULL);
	new->last_instr = NULL;
	new->next = NULL;
	new->stack_a = copy_stack(state_from->stack_a);
	new->stack_b = copy_stack(state_from->stack_b);
	new->instructions = copy_instr(state_from->instructions);
	if (!(new->stack_a) || !(new->stack_b) || (state_from->instructions
			&& !(new->instructions)))
	{
		free_states(new);
		return (NULL);
	}
	temp = *states;
	while (temp && temp->next)
		temp = temp->next;
	if (temp)
		temp->next = new;
	else
		*states = new;
	return (new);
}

t_state	*new_empty_state(t_list *stack_a, t_list *stack_b, size_t max_size)
{
	t_state	*state;

	state = malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	if (!stack_a)
	{
		state->stack_a = new_empty_stack(max_size);
		if (!state->stack_a)
		{
			free(state);
			return (NULL);
		}
	}
	else
		state->stack_a = copy_stack(stack_a);
	check(state, stack_b, max_size);
	state->instructions = NULL;
	state->last_instr = NULL;
	state->next = NULL;
	return (state);
}
