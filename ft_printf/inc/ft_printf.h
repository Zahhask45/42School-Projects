/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_printf.h                                                _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2025/12/03 18:18:13 by jodos-sa                 `----'`         */
/*   Updated: 2026/01/04 14:51:14 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <stddef.h>

# define BASE "0123456789abcdef"
/*
** A structure to hold all formatting options parsed from the format string.
** %[flags][width][.precision]type
*/
typedef struct s_format
{
	int		minus;		// '-' flag
	int		plus;		// '+' flag
	int		space;		// ' ' flag
	int		hash;		// '#' flag
	int		zero;		// '0' flag
	int		width;		// field width
	int		wildcard;
	int		precision;	// precision (dot followed by a number)
	char	type;		// conversion type (c, s, p, d, i, u, x, X, %)
	char	length[3];
}			t_format;

// Main function
int			ft_printf(const char *format, ...);

// Parser functions
void		check_length(const char **format, t_format *fmt);
void		check_type(const char **format, t_format *fmt);
void		ft_parse_wildcard(t_format *fmt, va_list args);
void		parse_format_specifier(const char **format, t_format *fmt);

// Utility functions for prepending (prepend.c)
int			ft_prepend_middle(char **new, char **str, int zeros);
void		ft_prepend_zeros(char **str, t_format *fmt);
void		ft_prepend_sign(char **str);
void		ft_prepend_hex(char **str);
void		ft_prepend_alternative(char **str, t_format *fmt);
void		ft_prepend_space(char **str);

// Utility functions for conversion (utils.c)
void		ft_to_upper(char *str);
int			ft_abs(long num);
int			ft_num_len(ssize_t num, int base);
void		ft_itoa_base(ssize_t num, int base, char **str);
int			ft_unum_len(size_t num, int base);
void		ft_utoa_base(size_t num, int base, char **str);

// Utility functions for printing basic types (prints.c)
int			ft_print_char(int c, t_format *fmt);
int			ft_print_str(char *s, t_format *fmt);
int			ft_print_udigit(size_t n, int base, int is_upper, t_format *fmt);
int			ft_print_digit(ssize_t n, int base, int is_upper, t_format *fmt);
int			ft_print_ptr(void *p, t_format *fmt);

// Utility functions for format parsing (format.c)
void		format_init(t_format *fmt);
int			check_valid_format(t_format *fmt);
void		flag_parser(const char **format, t_format *fmt);

// Utility functions for string manipulation (string_utils.c)
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(const char *str);
void		ft_strlcpy(char *dst, const char *src, size_t size);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);

//Utility functions for flag handling (flags.c)
void		handle_flags(t_format *fmt, char **str);

//Utility functions for convert type (convert.c)
int			ft_convert_int(va_list args, t_format *fmt);
int			ft_convert_uint(va_list args, int base, int up, t_format *fmt);

int			ft_print_width(t_format *fmt);

#endif
