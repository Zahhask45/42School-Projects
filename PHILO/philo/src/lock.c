/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:56:10 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/29 16:27:09 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	lock_right_fork(t_philo *philo)
{
	int	x;

	pthread_mutex_lock(&philo->info->forks[philo->r_fork]);
	x = philo->info->fork_status[philo->r_fork] == FREE;
	pthread_mutex_unlock(&philo->info->forks[philo->r_fork]);
	return (x);
}

int	lock_left_fork(t_philo *philo)
{
	int	x;

	pthread_mutex_lock(&philo->info->forks[philo->l_fork]);
	x = philo->info->fork_status[philo->l_fork] == FREE;
	pthread_mutex_unlock(&philo->info->forks[philo->l_fork]);
	return (x);
}

void	ssleep(t_philo *philo)
{
	print_status(philo, "is sleeping", "BLUE");
	ft_usleep((philo->info->time_to_sleep * 1000));
}

void	think(t_philo *philo)
{
	print_status(philo, "is thinking", "GREEN");
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}
