/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:49:05 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/16 14:41:04 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	free_prg(t_all *prg)
{
	free_instr(prg->last_inst);
	free(prg->stack_a.value);
	free(prg->stack_b.value);
	return (0);
}
