/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/15 18:39:47 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap first two nodes of a
void	sa(t_stack **a)
{
	if (list_size(*a) >= 2)
	{
		*a = node_swap(*a, (*a)->next);
		ft_printf("sa\n");
	}
}

//swap first two nodes of b
void	sb(t_stack **b)
{
	if (list_size(*b) >= 2)
	{
		*b = node_swap(*b, (*b)->next);
		ft_printf("sb\n");
	}
}

// //swap first two nodes of both
void	ss(t_stack **a, t_stack **b)
{
	if (list_size(*a) >= 2)
		*a = node_swap(*a, (*a)->next);
	if (list_size(*b) >= 2)
		*b = node_swap(*b, (*b)->next);
	ft_printf("ss\n");
}
