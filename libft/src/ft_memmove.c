/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:47:59 by jodos-sa          #+#    #+#             */
/*   Updated: 2022/11/05 12:05:08 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	l;

	if (!dest && !src)
		return (0);
	l = 0;
	if ((size_t)dest - (size_t)src < n)
	{
		l = n - 1;
		while (l < n)
		{
			((unsigned char *)dest)[l] = ((unsigned char *)src)[l];
			l--;
		}
	}
	else
	{
		while (l < n)
		{
			((unsigned char *)dest)[l] = ((unsigned char *)src)[l];
			l++;
		}
	}
	return (dest);
}
/*
int	main()
{
	char	src[5] = "Nice";
	char	dest[10] = "AAAA good";

	memmove(dest, src, 5);

	char    src2[5] = "Nice";
        char    dest2[10] = "AAAA good";

	ft_memmove(dest2, src2, 5);
	printf("NORMAL: %s", dest);
	printf("\nMINE:   %s", dest2);
}*/
