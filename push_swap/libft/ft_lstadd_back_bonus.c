/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:03:11 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/27 14:20:08 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//add t_list *new to the end of linked list

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy;

	if (!*lst)
		*lst = new;
	else
	{
		copy = ft_lstlast(*lst);
		copy->next = new;
	}
}
