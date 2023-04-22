/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:38:37 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/17 17:18:52 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	order_stack(t_list *stack)
{
	size_t	i;

	i = 0;
	if (stack->size == 0)
		return (1);
	while (i < stack->size - 1)
	{
		if ((stack->value[i] >= stack->value[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	stack_contains(t_list *stack, int num)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->value[i++] == num)
			return (1);
	}
	return (0);
}

int	start_inst(t_all *prg)
{
	int		ret;
	char	buff[1];

	prg->last_inst = NULL;
	ret = get_instruction(&prg->last_inst);
	while (ret > 0)
		ret = get_instruction(&prg->last_inst);
	if (ret < 0)
	{
		buff[0] = ' ';
		while (buff[0] && read(STDIN_FILENO, &buff, 1))
			;
		free_instr(prg->last_inst);
		free(prg->stack_a.value);
		free(prg->stack_b.value);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
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
		if (begin(--argc, &argv[2], &prg.stack_a, &prg.stack_b))
			return (1);
	}
	else if (begin(argc, &argv[1], &prg.stack_a, &prg.stack_b))
		return (1);
	if (start_inst(&prg))
		return (1);
	if (prg.debug)
		print_instructions(prg.last_inst);
	if (prg.debug)
		print_stacks(&prg.stack_a, &prg.stack_b);
	pick_instruction(prg.last_inst, &prg.stack_a, &prg.stack_b, prg.debug);
	if (order_stack(&prg.stack_a) || prg.stack_b.size)
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
	return (free_prg(&prg));
}
