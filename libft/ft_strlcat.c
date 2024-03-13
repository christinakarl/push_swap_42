/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:53:58 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/27 14:31:00 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	i = 0;
	j = 0;
	if (size == 0)
		return (slen);
	if (size < dlen)
		return (size + slen);
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && i < (size - 1))
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dlen + slen);
}
