/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:03:11 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/27 14:20:08 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*copy;

	copy = (t_list *)malloc(sizeof(*copy));
	if (!copy)
		return (NULL);
	copy->content = content;
	copy->next = NULL;
	return (copy);
}
