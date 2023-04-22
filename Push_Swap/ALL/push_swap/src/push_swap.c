/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:32:24 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/16 14:05:28 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapback.h"

size_t	count_instructions(t_instruct *instr)
{
	size_t	many;

	many = 0;
	while (instr)
	{
		many++;
		instr = instr->next;
	}
	return (many);
}

int	pick_solut(t_all *prg, t_state *states)
{
	t_state	*solution;
	t_state	*temp_state;

	solution = NULL;
	temp_state = states->next;
	while (temp_state)
	{
		if (!solution || count_instructions(temp_state->instructions)
			< count_instructions(solution->instructions))
			solution = temp_state;
		temp_state = temp_state->next;
	}
	if (!solution)
		solution = states;
	if (!solution->instructions)
		return (0);
	pick_instruction(solution->instructions, &prg->stack_a, &prg->stack_b,
		prg->debug);
	prg->last_inst = copy_instr(solution->instructions);
	if (!prg->last_inst)
	{
		free_states(states);
		return (1);
	}
	return (0);
}

int	realign_and_fill_a(t_all *prg)
{
	t_instruct	*temp;

	if (prg->stack_b.size > 1 && align_stack_b(prg))
		return (1);
	while (prg->stack_b.size)
	{
		if (prg->stack_b.value[0] > prg->stack_a.value[prg->stack_a.size - 1]
			|| (prg->stack_b.value[0] < prg->stack_a.value[0]
				&& prg->stack_a.value[0] < prg->stack_a.value[prg->stack_a.size
					- 1]))
			temp = add_instr(&prg->last_inst, "pa");
		else
			temp = add_instr(&prg->last_inst, "rra");
		if (!temp)
			return (1);
		pick_instruction(temp, &prg->stack_a, &prg->stack_b, prg->debug);
	}
	if (align_stack_a(prg))
		return (1);
	return (0);
}

int	resolve(t_all *prg)
{
	t_state	*states;

	states = new_empty_state(&prg->stack_a, &prg->stack_b,
			prg->stack_a.max_size);
	if (!states)
		return (1);
	if (prg->stack_a.size > 5
		&& (create_states_resolution(&states) || large_resolve(states)))
		return (1);
	if (pick_solut(prg, states))
		return (1);
	free_states(states);
	if (bruteforce_order_a(prg))
		return (1);
	if (realign_and_fill_a(prg))
		return (1);
	if (order_stack(&prg->stack_a, ASC))
		bruteforce_order_a(prg);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	prg;

	if (--argc < 1 || (!ft_strcmp(argv[1], "-v") && argc == 1))
		return (0);
	prg.debug = 0;
	if (!ft_strcmp(argv[1], "-v"))
	{
		prg.debug = 1;
		if (start(--argc, &argv[2], &prg.stack_a, &prg.stack_b))
			return (1);
	}
	else if (start(argc, &argv[1], &prg.stack_a, &prg.stack_b))
		return (1);
	if (prg.debug)
		print_stacks(&prg.stack_a, &prg.stack_b);
	prg.last_inst = NULL;
	if (order_stack(&prg.stack_a, ASC) && resolve(&prg))
	{
		free_instr(prg.last_inst);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	print_instructions(prg.last_inst);
	free_prg(&prg);
	return (0);
}
