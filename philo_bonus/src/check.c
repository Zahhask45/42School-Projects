/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:06:14 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/08/07 13:27:34 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	philo_must_eat(t_info *info)
{
	if (info->must_eat == info->full && info->id == info->how_many)
	{
		info->full_total++;
		sem_post(info->end);
	}
}

int	check_numbers(char **argv, int argc)
{
	if (ft_isnumber(argv[1]) || ft_isnumber(argv[2])
		|| ft_isnumber(argv[3]) || ft_isnumber(argv[4]))
	{
		write (STDERR_FILENO, "Invalid args\n", 14);
		return (EXIT_FAILURE);
	}
	if (argc == 6)
	{
		if (ft_isnumber(argv[5]))
		{
			write (STDERR_FILENO, "Invalid args\n", 14);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
