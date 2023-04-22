/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:49:04 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/16 14:05:25 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapback.h"

char	*ft_strdup_char(const char *str, char stop)
{
	int		i;
	char	*pt;

	i = 0;
	while (str[i] && str[i] != stop)
		i++;
	pt = malloc((i + 1) * sizeof(char));
	if (!pt)
		return (0);
	i = -1;
	while (str[++i] && str[i] != stop)
		pt[i] = str[i];
	pt[i] = '\0';
	return (pt);
}

int	fill_stack_one(char *arg, t_list *stack, size_t *stack_nb)
{
	int		num;
	char	*str;

	while (*arg)
	{
		while (*arg && *arg == ' ')
			arg++;
		if (!*arg)
			break ;
		str = ft_strdup_char(arg, ' ');
		if (ft_atoi(str, &num))
		{
			free(str);
			return (1);
		}
		free(str);
		if (stack_contains(stack, num))
			return (1);
		stack->value[(*stack_nb)++] = num;
		stack->size++;
		while (*arg && *arg != ' ')
			arg++;
	}
	return (0);
}

int	fill_stack(int argc, char **argv, t_list *stack)
{
	size_t	x;
	size_t	y;
	char	*ptr;

	x = 0;
	y = 0;
	while (x < (size_t)argc)
	{
		ptr = argv[x];
		if (fill_stack_one(ptr, stack, &y))
			return (1);
		x++;
	}
	return (0);
}

size_t	count_stack(int argc, char *argv[])
{
	size_t	x;
	size_t	y;
	size_t	size;

	size = 0;
	x = 0;
	while (x < (size_t)argc)
	{
		y = 0;
		while (argv[x][y])
		{
			if (((!y) || argv[x][y - 1] == ' ') && argv[x][y] != ' ')
				size++;
			y++;
		}
		x++;
	}
	if (!size)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (size);
}

int	start(int argc, char *argv[], t_list *stack_a, t_list *stack_b)
{
	size_t	stack_size;

	stack_size = count_stack(argc, argv);
	stack_a->value = malloc(sizeof(int) * stack_size);
	if (!stack_a->value)
		return (write(STDERR_FILENO, "Error\n", 6));
	stack_b->value = malloc(sizeof(int) * stack_size);
	if (!stack_b->value)
	{
		free(stack_a->value);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	stack_a->max_size = stack_size;
	stack_b->max_size = stack_size;
	stack_a->size = 0;
	stack_b->size = 0;
	if (fill_stack(argc, argv, stack_a))
	{
		free(stack_a->value);
		free(stack_b->value);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}
