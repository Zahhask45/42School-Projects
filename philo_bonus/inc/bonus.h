/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:45:42 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/08/06 17:06:41 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stdatomic.h>
# include <semaphore.h>
# include <signal.h>

# define THINK 1
# define ZZZ 2
# define GRAB 3
# define EAT 4

# define RED "\033[1;31m"
# define GREY "\033[1;37m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define MID "\033[9m"
# define END "\033[0m"

typedef struct s_info
{
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			time;
	int				must_eat;
	int				how_many;
	int				full_total;
	unsigned int	*pid;
	int				state;
	int				id;
	sem_t			*sem;
	sem_t			*psem;
	sem_t			*end;
	_Atomic long	lasteat;
	atomic_int		full;

}			t_info;

/*========================================================================
 *                           Utils.c
 *========================================================================*/

long	get_time(void);
int		ft_isdigit(int c);
int		ft_isnumber(char *str);
int		ft_atoi(char *str);
void	clean(t_info *info, int nforks);
int		check_numbers(char **argv, int argc);
void	philo_must_eat(t_info *info);

#endif