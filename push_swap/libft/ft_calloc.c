/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:50:10 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/28 15:49:39 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*cal;

	cal = (char *)malloc(size * count);
	if (cal == NULL)
		return (NULL);
	ft_memset(cal, 0, size * count);
	return (cal);
}
