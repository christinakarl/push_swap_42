/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/15 18:41:46 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//redirect to the right algorithm depending on length
void	direct_algo(t_stack **a, t_stack **b)
{
	int	len;

	len = list_size(*a);
	if (len == 1 || check_order(*a) == 0)
		return ;
	else if (len == 2)
		sa(a);
	else if (len == 3)
		algo_three(a);
	else if (len <= 5)
		algo_five(a, b);
	else if (check_reverse_order(*a) == 0 && len > 5)
	{
		while ((*a))
			pb(a, b);
		while (*b)
		{
			rrb(b);
			pa(a, b);
		}
		return ;
	}
	else
		algo_more(a, b);
}

//algo for 3 elements, max 2 actions
void	algo_three(t_stack **a)
{
	t_stack	*third;

	third = (*a)->next->next;
	if ((*a)->index > (*a)->next->index)
	{
		if ((*a)->index > third->index)
			ra(a);
		else
			sa(a);
	}
	else if ((*a)->next->index > (*a)->index)
	{
		if ((*a)->next->index > third->index)
			rra(a);
	}
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

//algo for 4 or 5 elements, max 12 actions
void	algo_five(t_stack **a, t_stack **b)
{
	int	push;

	push = 0;
	while ((*a) && push < 2)
	{
		while ((*a)->index != push)
		{
			if (find_position(*a, push) > 2)
				rra(a);
			else
				ra(a);
		}
		pb(a, b);
		if (list_size(*a) > 3)
			push++;
		else
			break ;
	}
	algo_three(a);
	pa(a, b);
	pa(a, b);
}

//algo for >5 elements: 1. push all to b except of 3, 2. algo_three,
// 3. find to_nodes for all of b nodes,
//4. check which one can be movd most easily (least operations)
// 5. mov it, 6. repeat until !*b
void	algo_more(t_stack **a, t_stack **b)
{
	int	bpos;

	while (list_size(*a) > 3)
		pb(a, b);
	algo_three(a);
	while (*b && *a)
	{
		bpos = -1;
		set_lm(a, b);
		while (++bpos < (*b)->len)
			set_tp(a, b, bpos);
		set_move(*a, b);
		move_best_option(a, b, find_best_option(*b));
		pa(a, b);
	}
	right_order(a);
}
