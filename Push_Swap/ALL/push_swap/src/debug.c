/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:52:00 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/08 14:56:55 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapback.h"

void	write_n_char(int n, char c)
{
	while (n-- > 0)
		write(STDOUT_FILENO, &c, 1);
}

int	size_nbr(int n)
{
	long	nnbr;
	int		size;

	size = 0;
	nnbr = n;
	if (nnbr < 0)
	{
		size = 1;
		nnbr *= -1;
	}
	if (nnbr != 0)
	{
		if (nnbr / 10 > 0)
			size += size_nbr(nnbr / 10);
		size++;
		return (size);
	}
	if (n == 0)
		size++;
	return (size);
}

int	get_max_size_nbr_stack(t_list *stack)
{
	int		size;
	size_t	i;

	if (!stack->size)
		size = 1;
	else
		size = size_nbr(stack->value[0]);
	i = 1;
	while (i < stack->size)
	{
		if (size < size_nbr(stack->value[i]))
			size = size_nbr(stack->value[i]);
		i++;
	}
	return (size);
}
