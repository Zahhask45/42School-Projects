/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:13:27 by jodos-sa          #+#    #+#             */
/*   Updated: 2022/11/05 12:27:31 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	i;

	if (!dst && !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	i = 0;
	d = ft_strlen(dst);
	while (src[i] != '\0' && d + 1 < size)
	{
		dst[d] = src[i];
		i++;
		d++;
	}
	dst[d] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
