/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/15 18:40:30 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//last to first for a, reverse rotate rra
void	rra(t_stack **a)
{
	int		len;
	t_stack	*temp;

	*a = first_node(*a);
	len = list_size(*a);
	temp = last_node(*a);
	if (len >= 2)
	{
		*a = node_rotate(temp);
		ft_printf("rra\n");
	}
}

//last to first for b, reverse rotate rrb
void	rrb(t_stack **b)
{
	int		len;
	t_stack	*temp;

	len = list_size(*b);
	temp = last_node(*b);
	if (len >= 2)
	{
		*b = node_rotate(temp);
		ft_printf("rrb\n");
	}
}

//last to first for both rrr
void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_b = last_node(*b);
	temp_a = last_node(*a);
	if (list_size(*a) >= 2)
		*a = node_rotate(temp_a);
	if (list_size(*b) >= 2)
		*b = node_rotate(temp_b);
	ft_printf("rrr\n");
}

//first from a to b, a, nothing if a is empty pb
void	pb(t_stack **a, t_stack **b)
{
	if (*a != NULL)
	{
		node_push(a, b);
		ft_printf("pb\n");
	}
}

//first from b to a, a, nothin if b is empty pa
void	pa(t_stack **a, t_stack **b)
{
	if (*b != NULL)
	{
		node_push(b, a);
		ft_printf("pa\n");
	}
}
