/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:45:00 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/08/07 13:27:09 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	print(t_info *i, int type)
{
	sem_wait(i->psem);
	if (type == EAT)
		printf(YELLOW "%lu %d is eating\n", get_time() - i->time, i->id);
	else if (type == GRAB)
		printf(GREY "%lu %d has taken a fork\n", get_time() - i->time, i->id);
	else if (type == ZZZ)
		printf(BLUE "%lu %d is sleeping\n", get_time() - i->time, i->id);
	else if (type == THINK)
		printf(GREEN "%lu %d is thinking\n", get_time() - i->time, i->id);
	sem_post(i->psem);
}

void	*died(void *info)
{
	t_info	*another;

	another = (t_info *)info;
	while (1)
	{
		if (get_time() - another->lasteat > another->time_to_die)
		{
			sem_wait(another->psem);
			printf(MID RED"%lu %d died\n", 
				get_time() - another->time, another->id);
			sem_post(another->end);
		}
	}
}

void	routine(t_info *info)
{
	pthread_t	tenor;

	info->lasteat = get_time();
	pthread_create(&tenor, NULL, died, info);
	while (1)
	{
		print(info, THINK);
		sem_wait(info->sem);
		print(info, GRAB);
		sem_wait(info->sem);
		print(info, GRAB);
		print(info, EAT);
		info->full++;
		philo_must_eat(info);
		info->lasteat = get_time();
		usleep(info->time_to_eat * 1000);
		sem_post(info->sem);
		sem_post(info->sem);
		print(info, ZZZ);
		usleep(info->time_to_sleep * 1000);
		usleep(info->time_to_die - info->time_to_eat - info->time_to_sleep / 2);
	}
}

void	start(t_info *info, int argc, char **argv, int *nforks)
{
	if (argc != 5 && argc != 6)
	{
		write (STDERR_FILENO, "Invalid args\n", 14);
		exit (EXIT_FAILURE);
	}
	if (check_numbers(argv, argc))
		exit (EXIT_FAILURE);
	*nforks = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = -1;
	info->full = 0;
	info->id = -1;
	info->pid = malloc(*nforks * 4);
	sem_unlink("sem");
	sem_unlink("psem");
	sem_unlink("end");
	info->sem = sem_open("sem", O_CREAT, 0600, *nforks);
	info->psem = sem_open("psem", O_CREAT, 0600, 1);
	info->end = sem_open("end", O_CREAT, 0600, 0);
	info->time = get_time();
}

int	main(int argc, char **argv)
{
	t_info			info;
	int				nforks;
	int				i;
	unsigned int	fork_id;

	start(&info, argc, argv, &nforks);
	info.how_many = nforks;
	info.full_total = 0;
	fork_id = -1;
	i = -1;
	while (++i < nforks && fork_id != 0)
	{
		fork_id = fork();
		if (fork_id != 0)
			info.pid[i] = fork_id;
	}
	info.id = i;
	if (fork_id == 0)
		routine(&info);
	else
		clean(&info, nforks);
}
