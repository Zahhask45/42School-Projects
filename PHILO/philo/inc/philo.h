/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:24:42 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/29 16:28:28 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[0;31m"
# define GREY "\033[0;37m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;36m"
# define GREEN "\033[0;32m"

# define FREE 0
# define LOCK 1

typedef struct s_info
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				finished_philos;
	int				end;
	int				*fork_status;
	size_t			start;
	pthread_mutex_t	mtx_end;
	pthread_mutex_t	phil;
	pthread_mutex_t	*forks;
}					t_info;

typedef struct s_philo
{
	t_info			*info;
	int				r_fork;
	int				l_fork;
	int				num;
	int				num_eat;
	int				x;
	size_t			last_eat;
	pthread_mutex_t	eat;
	pthread_mutex_t	print;
}					t_philo;

//========================================================
//						start.c
//========================================================

int					start_info(t_info *info);
t_philo				*start_philo(t_info *info);
int					start_args(int argc, char **argv, t_info *info);

//========================================================
//						utils.c
//========================================================

size_t				get_sec(void);
void				ft_usleep(__useconds_t time);
void				print_status(t_philo *philo, char *status, char *color);
int					ft_atoi(char *str);
void				ft_time(t_philo *philo);

//========================================================
//						survive.c
//========================================================

void				*philo_life(void *arg);

//========================================================
//						finish.c
//========================================================

void				kill_them(pthread_t *threads, t_info *info, t_philo *philo);
void				philo_death(t_philo *philo, t_info *info);

//========================================================
//						lock.c
//========================================================

int					lock_right_fork(t_philo *philo);
int					lock_left_fork(t_philo *philo);
void				ssleep(t_philo *philo);
void				think(t_philo *philo);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif