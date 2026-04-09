/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   string_utils.c                                             _             */
/*                                                            _ \'-_,#        */
/*   By: jodos-sa <jodos-sa@student.42porto.com>             _\'--','`|       */
/*                                                           \`---`  /        */
/*   Created: 2025/12/23 12:23:16 by jodos-sa                 `----'`         */
/*   Updated: 2026/01/04 14:44:40 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL)
		return (-1);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len++])
		;
	return (len - 1);
}

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while ((src[i] != '\0') && (i < size))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	l;

	l = 0;
	while (l < n)
	{
		((unsigned char *)s)[l] = c;
		l++;
	}
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	l;

	if (!dest && !src)
		return (0);
	l = 0;
	while (l < n)
	{
		((unsigned char *)dest)[l] = ((unsigned char *)src)[l];
		l++;
	}
	return (dest);
}
