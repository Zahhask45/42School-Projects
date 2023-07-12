/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:59:38 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/06/20 16:41:35 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_mutex_forks(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_philos)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
		{
			write(STDERR_FILENO, "Init mutex error\n", 18);
			return (1);
		}
	}
	return (0);
}

int	start_info(t_info *info)
{
	info->forks = malloc(info->num_philos * sizeof(pthread_mutex_t));
	info->fork_status = malloc(info->num_philos * sizeof(int));
	memset(info->fork_status, FREE, sizeof(int) * info->num_philos);
	if (!info->forks || !info->fork_status)
	{
		write(STDERR_FILENO, "Malloc Erro\n", 14);
		return (1);
	}
	info->finished_philos = 0;
	info->end = 0;
	if (start_mutex_forks(info) || pthread_mutex_init(&info->mtx_end, NULL)
		|| pthread_mutex_init(&info->phil, NULL))
	{
		write(2, "Init mutex error\n", 18);
		return (1);
	}
	info->start = get_sec();
	return (0);
}

t_philo	*start_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = malloc(info->num_philos * sizeof(t_philo));
	if (!philo)
		return (NULL);
	if (pthread_mutex_init(&philo->eat, NULL)
		|| pthread_mutex_init(&philo->print, NULL))
		return (NULL);
	i = -1;
	while (++i < info->num_philos)
	{
		philo[i].num = i + 1;
		philo[i].info = info;
		philo[i].l_fork = i;
		if (i == 0)
			philo[i].r_fork = info->num_philos - 1;
		else
			philo[i].r_fork = i -1;
		philo[i].last_eat = info->start;
		philo[i].num_eat = 0;
	}
	return (philo);
}

int	start_args(int argc, char **argv, t_info *info)
{
	int	i;
	
	if (argc != 5 && argc != 6)
	{
		write (STDERR_FILENO, "Invalid args\n", 14);
		return (EXIT_FAILURE);
	}
	info->num_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->must_eat = -1;
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	if (info->num_philos < 1 || info->time_to_die < 1 || info->time_to_eat < 1
		|| info->time_to_sleep < 1 || (argc == 6 && info->must_eat < 1))
	{
		write(STDERR_FILENO, "Invalid args\n", 14);
		return (EXIT_FAILURE);
	}
	return (0);
}
