/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:43:17 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/29 13:06:08 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	destroy_forks(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philos)
		pthread_mutex_destroy(&info->forks[i]);
	return (0);
}

void	kill_them(pthread_t *threads, t_info *info, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < info->num_philos)
	{
		pthread_join(threads[i], NULL);
	}
	pthread_mutex_destroy(&info->mtx_end);
	destroy_forks(info);
	free(info->fork_status);
	free(info->forks);
	free(info);
	free(threads);
	free(philo);
}

void	check_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat);
	if ((get_sec() - philo->last_eat) / 1000
		> (size_t)philo->info->time_to_die)
	{
		pthread_mutex_unlock(&philo->eat);
		print_status(philo, "died", "RED");
		pthread_mutex_lock(&philo->info->mtx_end);
		philo->info->end = 1;
		pthread_mutex_unlock(&philo->info->mtx_end);
	}
	else
		pthread_mutex_unlock(&philo->eat);
}

void	philo_death(t_philo *philo, t_info *info)
{
	int	i;
	int	x;

	pthread_mutex_lock(&philo->info->mtx_end);
	x = !info->end;
	pthread_mutex_unlock(&philo->info->mtx_end);
	while (x)
	{
		pthread_mutex_lock(&philo->info->mtx_end);
		x = !info->end;
		pthread_mutex_unlock(&philo->info->mtx_end);
		ft_usleep(2000);
		i = 0;
		while (x && i < info->num_philos)
		{
			pthread_mutex_lock(&philo->info->mtx_end);
			x = !info->end;
			pthread_mutex_unlock(&philo->info->mtx_end);
			check_philo(&philo[i]);
			i++;
		}
	}
	return ;
}
