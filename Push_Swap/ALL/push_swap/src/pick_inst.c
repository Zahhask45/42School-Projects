/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:51:58 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/03/05 15:52:01 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapback.h"

void	pick_instruction(t_instruct *inst, t_list *stack_a, t_list *stack_b,
		int debug)
{
	while (inst)
	{
		if (debug)
			print_instruction(inst);
		if (!ft_strcmp(inst->line, "sa") || !ft_strcmp(inst->line, "ss"))
			swap(stack_a);
		if (!ft_strcmp(inst->line, "sb") || !ft_strcmp(inst->line, "ss"))
			swap(stack_b);
		if (!ft_strcmp(inst->line, "pa"))
			push(stack_a, stack_b);
		if (!ft_strcmp(inst->line, "pb"))
			push(stack_b, stack_a);
		if (!ft_strcmp(inst->line, "ra") || !ft_strcmp(inst->line, "rr"))
			rotate(stack_a);
		if (!ft_strcmp(inst->line, "rb") || !ft_strcmp(inst->line, "rr"))
			rotate(stack_b);
		if (!ft_strcmp(inst->line, "rra") || !ft_strcmp(inst->line, "rrr"))
			reverse_rotate(stack_a);
		if (!ft_strcmp(inst->line, "rrb") || !ft_strcmp(inst->line, "rrr"))
			reverse_rotate(stack_b);
		if (debug)
			print_stacks(stack_a, stack_b);
		inst = inst->next;
	}
}

t_instruct	*copy_and_concat_instructions(t_instruct **instr,
											t_instruct *new)
{
	t_instruct	*ptr;
	t_instruct	*temp_instr;

	temp_instr = *instr;
	if (temp_instr)
	{
		while (temp_instr->next)
			temp_instr = temp_instr->next;
		temp_instr->next = copy_instr(new);
		if (!temp_instr->next)
			return (NULL);
		ptr = temp_instr->next;
		((t_instruct *)temp_instr->next)->prev = temp_instr;
	}
	else
	{
		*instr = copy_instr(new);
		ptr = *instr;
	}
	return (ptr);
}

t_instruct	*copy_instr(t_instruct *instr)
{
	t_instruct	*new;

	new = NULL;
	while (instr)
	{
		if (!(add_instr(&new, instr->line)))
		{
			free_instr(new);
			return (NULL);
		}
		instr = instr->next;
	}
	return (new);
}

t_instruct	*add_x_instructions(t_instruct **instr, char *line, size_t n)
{
	t_instruct	*begin;

	begin = NULL;
	if (n > 0)
	{
		begin = add_instr(instr, line);
		if (!begin)
			return (NULL);
		n--;
		while (n > 0)
		{
			if (!(add_instr(instr, line)))
			{
				free_instr(begin);
				return (NULL);
			}
			n--;
		}
	}
	return (begin);
}

t_instruct	*add_instr(t_instruct **instr, char *line)
{
	t_instruct	*temp;
	t_instruct	*new;

	new = malloc(sizeof(t_instruct));
	if (!new)
		return (NULL);
	new->line = ft_strdup(line);
	if (!new->line)
	{
		free(new);
		return (NULL);
	}
	new->prev = NULL;
	new->next = NULL;
	temp = *instr;
	while (temp && temp->next)
		temp = temp->next;
	if (temp)
	{
		new->prev = temp;
		temp->next = new;
	}
	else
		*instr = new;
	return (new);
}
