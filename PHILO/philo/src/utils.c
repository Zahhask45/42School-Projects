/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:57:46 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/29 16:28:06 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_sec(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	ft_usleep(__useconds_t time)
{
	size_t	t;

	t = get_sec();
	while (get_sec() - t < time)
		usleep(1);
}

void	print_status(t_philo *philo, char *status, char *color)
{
	pthread_mutex_lock(&philo->info->mtx_end);
	if (philo->info->end)
	{
		pthread_mutex_unlock(&philo->info->mtx_end);
		return ;
	}
	pthread_mutex_unlock(&philo->info->mtx_end);
	pthread_mutex_lock(&philo->print);
	(void)color;
	if (!ft_strncmp(color, "RED", 3))
		printf(RED "%zu %d %s\n", (get_sec() - philo->info->start) / 1000,
			philo->num, status);
	if (!ft_strncmp(color, "GREY", 4))
		printf(GREY "%zu %d %s\n", (get_sec() - philo->info->start) / 1000,
			philo->num, status);
	if (!ft_strncmp(color, "BLUE", 4))
		printf(BLUE "%zu %d %s\n", (get_sec() - philo->info->start) / 1000,
			philo->num, status);
	if (!ft_strncmp(color, "GREEN", 5))
		printf(GREEN "%zu %d %s\n", (get_sec() - philo->info->start) / 1000,
			philo->num, status);
	if (!ft_strncmp(color, "YELLOW", 6))
		printf(YELLOW "%zu %d %s\n", (get_sec() - philo->info->start) / 1000,
			philo->num, status);
	pthread_mutex_unlock(&philo->print);
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

void	ft_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat);
	philo->last_eat = get_sec();
	pthread_mutex_unlock(&philo->eat);
}
