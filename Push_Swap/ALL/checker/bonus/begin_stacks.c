/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:00:34 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/17 17:18:17 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strdup_char(const char *str, char stop)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i] && str[i] != stop)
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = -1;
	while (str[++i] && str[i] != stop)
		ptr[i] = str[i];
	ptr[i] = '\0';
	return (ptr);
}

int	fill_stack_arg(char *arg, t_list *stack, size_t *nb)
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
			return (EXIT_FAILURE);
		}
		free(str);
		if (stack_contains(stack, num))
			return (EXIT_FAILURE);
		stack->value[(*nb)++] = num;
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
		if (fill_stack_arg(ptr, stack, &y))
			return (EXIT_FAILURE);
		x++;
	}
	return (0);
}

int	count_stack_size(int argc, char **argv)
{
	size_t	x;
	size_t	y;
	size_t	size;

	size = 0;
	x = 0;
	while (x < (size_t)argc)
	{
		y = 0;
		if (check_only_num(argv[x]) != 0)
			exit(write(STDERR_FILENO, "Error\n", 6));
		if (*argv[x] == '\0')
			exit (write(STDERR_FILENO, "Error\n", 6));
		while (argv[x][y])
		{
			if (((!y) || argv[x][y - 1] == ' ') && argv[x][y] != ' ')
				size++;
			y++;
		}
		x++;
	}
	if (!size)
		exit(0);
	return (size);
}

int	begin(int argc, char **argv, t_list *stack_a, t_list *stack_b)
{
	size_t	stack_size;

	stack_size = count_stack_size(argc, argv);
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
