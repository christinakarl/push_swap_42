/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:54:56 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/28 11:47:12 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			chr;
	unsigned int			i;
	unsigned char			*s1;

	s1 = (unsigned char *)s;
	i = 0;
	chr = c;
	while (i < n)
	{
		if (s1[i] == chr)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
