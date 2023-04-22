/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:49:05 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/03/25 15:49:07 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapback.h"

void	free_instr(t_instruct *instr)
{
	t_instruct	*next;

	while (instr)
	{
		next = instr->next;
		free(instr->line);
		free(instr);
		instr = next;
	}
}

void	free_stack(t_list *stack)
{
	free(stack->value);
	free(stack);
}

void	free_prg(t_all *prg)
{
	free_instr(prg->last_inst);
	free(prg->stack_a.value);
	free(prg->stack_b.value);
}
