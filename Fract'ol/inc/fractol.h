/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:51:21 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/05/05 16:21:22 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 1080
# define WIDTH 1920

# define _END "\x1b[0m"
# define _RED "\x1b[31m"
# define _YELLOW "\x1b[33m"
# define _GREEN "\x1b[32m"

typedef struct s_all
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				color;
	int				fractol;
	double			**map;
	double			x;
	double			y;
	double			zoom;
	double			movex;
	double			movey;
	double			cre;
	double			cim;
	double			oldre;
	double			oldima;
	double			newre;
	double			newima;
	double			preal;
	double			pima;
	int				maxinter;
	int				i;
	double			clickx;
	double			clicky;
	double			tempx;
	double			tempy;
	int				movemouse;
	double			x2;
	double			y2;
}					t_all;

typedef struct s_color
{
	unsigned char	chan[3];
}					t_color;

/*
** color.c 
*/

void				putimage(t_all *prg, int x, int y, int color);
unsigned int		colormagic(int i, double x, double y);
int					print_xy(t_all *prg);
void				retrydraw(t_all *prg);

/*
** hooks.c 
*/
int					mousehook(int mousekey, int x, int y, t_all *prg);
int					keyhooks(int key, t_all *prg);

/*
** julia.c 
*/

void				julia(t_all *prg);

/*
** mandelbrot.c 
*/

void				mandel(t_all *prg);

/*
** something.c 
*/

void				something(t_all *prg);

/*
** start.c 
*/

void				start_fractol(t_all *prg);

/*
** util.c
*/

void				*ft_memalloc(size_t size);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strdel(char **as);
void				ft_putstr(char *s);
double				ft_atof(const char *str);

/*
** utils2.c 
*/

void				free_all(t_all *prg);
int					does_have_letters(char *str);

/*
** whichfractol.c
*/

void				which_fractol(t_all *prg);
void				zoomin(int x, int y, t_all *prg);
void				zoomout(int x, int y, t_all *prg);
int					motion(int x, int y, t_all *prg);

#endif
