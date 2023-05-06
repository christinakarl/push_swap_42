/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:19:20 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/27 18:35:50 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	a;
	char			*buf;

	buf = (char *) b;
	a = c;
	i = 0;
	while (i < len)
	{
		buf[i] = a;
		i++;
	}
	return (b);
}
