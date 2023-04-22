/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:46:38 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/16 14:05:29 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapback.h"

int	reverse_rotate_bruteforce_a(t_state **new_state, t_state *temp,
		size_t pos[2], t_list *stack_b)
{
	size_t		i;
	t_instruct	*temp_instr;

	temp_instr = temp->last_instr;
	i = 0;
	while (i++ < temp->stack_a->size / 2 && temp_instr
		&& (!ft_strcmp(temp_instr->line, "rra") || !ft_strcmp(temp_instr->line,
				"rrr")))
		temp_instr = temp->last_instr->prev;
	if (!temp->last_instr || ((ft_strcmp(temp->last_instr->line, "ra")
				&& ft_strcmp(temp->last_instr->line, "rr")
				&& i < temp->stack_a->size / 2)))
	{
		if (pos[0] > stack_b->size / 2 && !temp->stack_b->size && pos[1])
		{
			pos[1]--;
			if (!new_state_instruction(new_state, temp, "rrr"))
				return (1);
		}
		else if (!new_state_instruction(new_state, temp, "rra"))
			return (1);
	}
	return (0);
}

int	rotate_bruteforce_a(t_state **new_state, t_state *temp, size_t pos[2],
		t_list *stack_b)
{
	size_t		i;
	t_instruct	*temp_instr;

	temp_instr = temp->last_instr;
	i = 0;
	while (i++ < temp->stack_a->size / 2 && temp_instr
		&& (!ft_strcmp(temp_instr->line, "ra") || !ft_strcmp(temp_instr->line,
				"rr")))
		temp_instr = temp->last_instr->prev;
	if (!temp->last_instr || ((ft_strcmp(temp->last_instr->line, "rra")
				&& ft_strcmp(temp->last_instr->line, "rrr")
				&& i < temp->stack_a->size / 2)))
	{
		if (pos[0] <= stack_b->size / 2 && !temp->stack_b->size && pos[1])
		{
			pos[1]--;
			if (!new_state_instruction(new_state, temp, "rr"))
				return (1);
		}
		else if (!new_state_instruction(new_state, temp, "ra"))
			return (1);
	}
	return (0);
}

int	bruteforce_choice_a(t_state **new_state, t_state *temp, size_t pos[2],
		t_list *stack_b)
{
	if (temp->stack_b->size < 2 && (!temp->last_instr
			|| ft_strcmp(temp->last_instr->line, "pa"))
		&& !new_state_instruction(new_state, temp, "pb"))
		return (1);
	if (temp->stack_b->size > 0 && (!temp->last_instr
			|| ft_strcmp(temp->last_instr->line, "pb"))
		&& !new_state_instruction(new_state, temp, "pa"))
		return (1);
	if (!temp->last_instr || (ft_strcmp(temp->last_instr->line, "sa")
			&& ft_strcmp(temp->last_instr->line, "sb")
			&& ft_strcmp(temp->last_instr->line, "ss")))
	{
		if (!new_state_instruction(new_state, temp, "sa"))
			return (1);
		if (temp->stack_b->size > 1 && !new_state_instruction(new_state, temp,
				"sb"))
			return (1);
		if (temp->stack_b->size > 1 && !new_state_instruction(new_state, temp,
				"ss"))
			return (1);
	}
	if (rotate_bruteforce_a(new_state, temp, pos, stack_b))
		return (1);
	return (reverse_rotate_bruteforce_a(new_state, temp, pos, stack_b));
}
