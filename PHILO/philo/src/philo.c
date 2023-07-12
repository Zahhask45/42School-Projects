/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:27:06 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/06/20 16:37:25 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philos(pthread_t *threads, t_info *info, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < info->num_philos)
	{
		pthread_create(&threads[i], NULL, philo_life, &philo[i]);
		usleep(50);
	}
	return (0);
}

//ERROR IF ARG HAVE LETTERS -> should return error
int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_info		*info;
	pthread_t	*threads;

	info = malloc(sizeof(t_info));
	if (!info || start_args(argc, argv, info) || start_info(info))
		return (EXIT_FAILURE);
	philo = start_philo(info);
	threads = malloc(info->num_philos * sizeof(pthread_t));
	if (!philo || !threads || start_philos(threads, info, philo))
		return (EXIT_FAILURE);
	philo_death(philo, info);
	kill_them(threads, info, philo);
	return (EXIT_SUCCESS);
}
