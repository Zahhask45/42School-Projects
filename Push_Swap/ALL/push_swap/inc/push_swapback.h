/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swapback.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:39:02 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/04/07 18:59:07 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAPBACK_H
# define PUSH_SWAPBACK_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define _END "\x1b[0m"
# define _RED "\x1b[31m"
# define _YELLOW "\x1b[33m"
# define _GREEN "\x1b[32m"

# ifndef DEBUG
#  define DEBUG 0
# endif

# define DEPTH 5

# define ASC 0
# define DESC 1

typedef struct s_list
{
	int			*value;
	size_t		size;
	size_t		max_size;
}				t_list;

typedef struct s_intruct
{
	char		*line;
	void		*next;
	void		*prev;
}				t_instruct;

typedef struct s_state
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_instruct	*instructions;
	t_instruct	*last_instr;
	void		*next;
}				t_state;

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
** errors.c
*/

void			error(int argc, char **num);

/*
** start_stacks.c
*/

char			*ft_strdup_char(const char *str, char stop);
int				fill_stack_one(char *arg, t_list *stack, size_t *stack_nb);
int				fill_stack(int argc, char *argv[], t_list *stack);
size_t			count_stack(int argc, char *argv[]);
int				start(int argc, char *argv[], t_list *stack_a, t_list *stack_b);

/*
** utils.c
*/
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *str);
size_t			ft_strlen(const char *s);
void			ft_putnbr(int n);
int				ft_atoi(const char *str, int *num);

/*
** stacks.c
*/

int				order_stack(t_list *stack, int order);
int				stack_contains(t_list *stack, int num);
t_list			*new_empty_stack(size_t max_size);

/*
** copy_stack.c
*/

t_list			*copy_stack(t_list *stack);

/*
** align_stacks.c
*/

void			calcul_align_a(size_t *pos, size_t *mvt, t_list *stack_a,
					t_list *stack_b);
void			calcul_align_b(size_t *pos, size_t *mvt, t_list *stack_b);
int				align_stack_a(t_all *prg);
int				align_stack_b(t_all *prg);

/*
** pick_inst.c
*/

void			pick_instruction(t_instruct *inst, t_list *stack_a,
					t_list *stack_b, int debug);
t_instruct		*copy_and_concat_instructions(t_instruct **instr,
					t_instruct *new);
t_instruct		*copy_instr(t_instruct *instr);
t_instruct		*add_x_instructions(t_instruct **instr, char *line, size_t n);
t_instruct		*add_instr(t_instruct **instr, char *line);

/*
** print.c
*/

void			print_instruction(t_instruct *instr);
void			print_instructions(t_instruct *instr);
void			print_bottom_stack(int max_size_nbr[2]);
void			print_numbers_stacks(int max_size, int max_size_nbr[2],
					t_list *stack_a, t_list *stack_b);
void			print_stacks(t_list *stack_a, t_list *stack_b);

/*
** resolution.c
*/

int				create_states_resolution(t_state **states);
t_instruct		*rotate_a(t_state *state, size_t min[2], size_t min_mvt[2]);
t_instruct		*another_rotate(t_state *state);
int				large_resolve(t_state *states);

/*
** cleaner.c
*/

void			free_instr(t_instruct *instr);
void			free_stack(t_list *stack);
void			free_prg(t_all *prg);

/*
** states.c
*/

void			check(t_state *state, t_list *stack, size_t max_size);
t_state			*new_state_instruction(t_state **states, t_state *old_state,
					char *line);
void			free_states(t_state *states);
t_state			*add_state(t_state **states, t_state *state_from);
t_state			*new_empty_state(t_list *stack_a, t_list *stack_b,
					size_t max_size);

/*
** debug.c
*/

void			write_n_char(int n, char c);
int				size_nbr(int n);
int				get_max_size_nbr_stack(t_list *stack);

/*
** bruteforce.c
*/

int				check_bruteforce_solution(t_state *states, t_state **result);
t_state			*pick_bruteforce(t_state *states, size_t pos[2],
					t_list *stack_b);
int				bruteforce_order_a(t_all *prg);

/*
** bruteforce_operations.c
*/

int				reverse_rotate_bruteforce_a(t_state **new_state, t_state *temp,
					size_t pos[2], t_list *stack_b);
int				rotate_bruteforce_a(t_state **new_state, t_state *temp,
					size_t pos[2], t_list *stack_b);
int				bruteforce_choice_a(t_state **new_state, t_state *temp,
					size_t pos[2], t_list *stack_b);

/*
** movements.c
*/

int				can_pb(t_list *stack_a, t_list *stack_b);
size_t			closer_pos_to_inf(int nb, t_list *stack);
size_t			less_mvt_at_begin(size_t minimal, size_t *min_mvt,
					t_list *stack_a, t_list *stack_b);
size_t			less_mvt_at_end(size_t minimal, size_t *min_mvt,
					t_list *stack_a, t_list *stack_b);

#endif
