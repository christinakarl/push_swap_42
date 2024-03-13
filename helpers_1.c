/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/05/06 15:04:21 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//find the smallest element in a stack
int	find_smallest(t_stack *b)
{
	int	i;
	int	s;

	s = b->index;
	i = 0;
	while (b)
	{
		if (b->index < s)
		{
			s = b->index;
			i = b->pos;
		}
		b = b->next;
	}
	return (i);
}

//find the position of an element in the stack
int	find_position(t_stack *list, int find)
{
	int		pos;

	pos = 0;
	while (list)
	{
		if (list->index == find)
			return (pos);
		list = list->next;
		pos++;
	}
	return (pos);
}

//repeat a rotate/swap/push action multiple times
void	rep_act2(t_stack **a, t_stack **b, \
				void (*act)(t_stack **, t_stack **), int rep)
{
	if (rep == 0)
		return ;
	while (rep > 0)
	{
		act(a, b);
		rep--;
	}
}

//repeat a rotate/swap/push action multiple times, only one stack
void	rep_act1(t_stack **x, void (*act)(t_stack **), int rep)
{
	if (rep == 0)
		return ;
	while (rep > 0)
	{
		act(x);
		rep--;
	}
}

/*how many double rotations are needed if a & b elements
are both positioned > or < median*/
int	double_rot(int x, int y, int flag)
{
	int	nb;

	nb = 0;
	if (flag == MOVE)
	{
		if (x < y)
			nb = x;
		else
			nb = y;
	}
	else if (flag == SET_MOVE)
	{
		if (x < y)
			nb = y;
		else
			nb = x;
	}
	return (nb);
}
