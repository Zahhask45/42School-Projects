/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:07:05 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/17 14:23:32 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_bzero(void *str, size_t n)
{
	char	*tmp;

	while (n--)
	{
		tmp = (char *)str;
		*tmp = 0;
		str++;
	}
}

int	check(char *line)
{
	if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb") && ft_strcmp(line, "ss")
		&& ft_strcmp(line, "pa") && ft_strcmp(line, "pb") && ft_strcmp(line,
			"ra") && ft_strcmp(line, "rb") && ft_strcmp(line, "rr")
		&& ft_strcmp(line, "rra") && ft_strcmp(line, "rrb") && ft_strcmp(line,
			"rrr"))
		return (1);
	return (0);
}

int	get_instruction(t_instruct **instr)
{
	int		ret;
	char	line[4];

	ft_bzero(line, 4);
	ret = read(STDIN_FILENO, line, 3);
	if (ret <= 0)
		return (ret);
	if (line[2] != '\n')
	{
		if (line[0] == '\n' || line[1] == '\n')
			return (-1);
		if (read(STDIN_FILENO, line + 3, 1) < 0 || line[3] != '\n')
			return (-1);
		line[3] = '\0';
	}
	else
		line[2] = '\0';
	if (check(line))
		return (-1);
	if (add_instr(instr, line))
		return (-1);
	return (1);
}
