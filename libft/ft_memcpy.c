/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:24:09 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/28 09:54:23 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s2;
	char	*s1;
	size_t	i;

	i = 0;
	s1 = (char *)dst;
	s2 = (char *)src;
	if (!dst && !s2)
		return (0);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
