/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:51:58 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/16 14:57:46 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pick_instruction(t_instruct *inst, t_list *stack_a, t_list *stack_b,
		int debug)
{
	while (inst)
	{
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
			print_debug_instruction(inst, stack_a, stack_b);
		inst = inst->next;
	}
}

int	add_instr(t_instruct **instr, char *line)
{
	t_instruct	*temp;
	t_instruct	*new;

	new = malloc(sizeof(t_instruct));
	if (!new)
		return (1);
	new->line = ft_strdup(line);
	new->next = NULL;
	temp = *instr;
	while (temp && temp->next)
		temp = temp->next;
	if (temp)
		temp->next = new;
	else
		*instr = new;
	return (0);
}
