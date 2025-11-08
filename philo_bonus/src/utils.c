/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:19:12 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/08/06 13:50:55 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000LL + time.tv_usec / 1000);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_atoi(char *str)
{
	long		number;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		str++;
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (number > 2147483647)
			return (-1);
		number = number * 10 + *str - '0';
		str++;
	}
	return (number);
}

void	clean(t_info *info, int nforks)
{
	int	i;

	sem_wait(info->end);
	i = -1;
	while (++i < nforks)
		kill(info->pid[i], SIGTERM);
	waitpid(-1, NULL, 0);
	free(info->pid);
}
