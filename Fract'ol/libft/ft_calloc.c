/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:08:54 by jodos-sa          #+#    #+#             */
/*   Updated: 2022/11/05 16:14:05 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	nmemb, size_t	size)
{
	size_t	tot_size;
	void	*dest;

	tot_size = size * nmemb;
	dest = malloc(tot_size);
	if (!dest)
		return (0);
	ft_memset(dest, 0, tot_size);
	return (dest);
}
