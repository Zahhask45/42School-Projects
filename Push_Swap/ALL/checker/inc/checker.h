/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:05:37 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/17 17:19:50 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

# define _END "\x1b[0m"
# define _RED "\x1b[31m"
# define _YELLOW "\x1b[33m"
# define _GREEN "\x1b[32m"

# ifndef DEBUG
#  define DEBUG 0
# endif

typedef struct s_list
{
	int			*value;
	size_t		size;
}				t_list;

typedef struct s_intruct
{
	char		*line;
	void		*next;
}				t_instruct;

typedef struct s_all
{
	t_list		stack_a;
	t_list		stack_b;
	t_instruct	*last_inst;
	int			debug;
}				t_all;

/*
** instrunc.c
*/

void			reverse_rotate(t_list *stack);
void			rotate(t_list *stack);
void			push(t_list *to, t_list *from);
void			swap(t_list *stack);

/*
** utils.c
*/

int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *str);
size_t			ft_strlen(const char *s);
void			ft_putnbr(int n);
int				ft_atoi(const char *str, int *num);

/*
** utils2.c
*/

int				check_only_num(char *argv);

/*
** pick_inst.c
*/

void			pick_instruction(t_instruct *inst, t_list *stack_a,
					t_list *stack_b, int debug);
int				add_instr(t_instruct **instr, char *line);

/*
** print.c
*/

void			print_bottom_stack(int max_size_nbr[2]);
void			print_numbers_stacks(int max_size, int max_size_nbr[2],
					t_list *stack_a, t_list *stack_b);
void			print_stacks(t_list *stack_a, t_list *stack_b);
void			print_instructions(t_instruct *instructions);
void			print_debug_instruction(t_instruct *instr,
					t_list *stack_a,
					t_list *stack_b);

/*
** cleaner.c
*/

void			free_instr(t_instruct *instr);
int				free_prg(t_all *prg);

/*
** debug.c
*/

void			write_n_char(int n, char c);
int				size_nbr(int n);
int				get_max_size_nbr_stack(t_list *stack);

/*
** BONUS
*/

/*
** checker.c
*/

int				stack_contains(t_list *stack, int num);

/*
** begin_stack.c
*/

char			*ft_strdup_char(const char *str, char stop);
int				fill_stack_arg(char *arg, t_list *stack, size_t *nb);
int				fill_stack(int argc, char **argv, t_list *stack);
int				count_stack_size(int argc, char **argv);
int				begin(int argc, char **argv, t_list *stack_a, t_list *stack_b);

/*
** get_instructions.c
*/

void			ft_bzero(void *str, size_t n);
int				get_instruction(t_instruct **instr);

#endif
