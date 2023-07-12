/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   survive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:05:29 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/29 15:12:36 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_must_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->mtx_end);
	pthread_mutex_lock(&philo->eat);
	if (philo->info->must_eat > 0 && ++philo->num_eat == philo->info->must_eat)
	{
		if (++philo->info->finished_philos == philo->info->num_philos)
		{
			philo->info->end = 1;
		}
	}
	pthread_mutex_unlock(&philo->eat);
	pthread_mutex_unlock(&philo->info->mtx_end);
}

void	eat(t_philo *philo)
{
	while (1)
	{
		philo->x = lock_right_fork(philo);
		if (philo->x)
		{
			pthread_mutex_lock(&philo->info->forks[philo->r_fork]);
			philo->info->fork_status[philo->r_fork] = LOCK;
			print_status(philo, "has taken a fork", "GREY");
			pthread_mutex_lock(&philo->info->forks[philo->l_fork]);
			philo->info->fork_status[philo->l_fork] = LOCK;
			print_status(philo, "has taken a fork", "GREY");
			ft_time(philo);
			print_status(philo, "is eating", "YELLOW");
			philo_must_eat(philo);
			ft_usleep(philo->info->time_to_eat * 1000);
			philo->info->fork_status[philo->r_fork] = FREE;
			pthread_mutex_unlock(&philo->info->forks[philo->r_fork]);
			philo->info->fork_status[philo->l_fork] = FREE;
			pthread_mutex_unlock(&philo->info->forks[philo->l_fork]);
			break ;
		}
		else
			usleep(500);
	}
}

void	eat_2(t_philo *philo)
{
	while (1)
	{
		philo->x = lock_left_fork(philo);
		if (philo->x)
		{
			pthread_mutex_lock(&philo->info->forks[philo->l_fork]);
			philo->info->fork_status[philo->l_fork] = LOCK;
			print_status(philo, "has taken a fork", "GREY");
			pthread_mutex_lock(&philo->info->forks[philo->r_fork]);
			philo->info->fork_status[philo->r_fork] = LOCK;
			print_status(philo, "has taken a fork", "GREY");
			ft_time(philo);
			print_status(philo, "is eating", "YELLOW");
			philo_must_eat(philo);
			ft_usleep(philo->info->time_to_eat * 1000);
			philo->info->fork_status[philo->l_fork] = FREE;
			pthread_mutex_unlock(&philo->info->forks[philo->l_fork]);
			philo->info->fork_status[philo->r_fork] = FREE;
			pthread_mutex_unlock(&philo->info->forks[philo->r_fork]);
			break ;
		}
		else
			usleep(500);
	}
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	int		x;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->info->mtx_end);
		x = (philo->info->end);
		pthread_mutex_unlock(&philo->info->mtx_end);
		if (x)
			break ;
		if (philo->num % 2 == 0)
			eat((t_philo *)arg);
		else
			eat_2((t_philo *)arg);
		ssleep((t_philo *)arg);
		think((t_philo *)arg);
	}
	return (NULL);
}
