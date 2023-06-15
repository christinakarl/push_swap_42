/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2. operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/15 18:38:12 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//first to last for a, rotate
void	ra(t_stack **a)
{
	int		len;

	len = list_size(*a);
	if (len >= 2)
	{
		*a = node_rotate(*a);
		ft_printf("ra\n");
	}
}

//first to last for b, rotate
void	rb(t_stack **b)
{
	int		len;

	len = list_size(*b);
	if (len >= 2)
	{
		*b = node_rotate(*b);
		ft_printf("rb\n");
	}
}

//first to last both
void	rr(t_stack **a, t_stack **b)
{
	if (list_size(*a) >= 2)
		*a = node_rotate(*a);
	if (list_size(*b) >= 2)
		*b = node_rotate(*b);
	ft_printf("rr\n");
}
