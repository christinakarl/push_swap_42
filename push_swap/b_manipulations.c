/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/05/06 15:04:21 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//set target for each element of b and position for each element of a & b
void	set_tp(t_stack **a, t_stack **b, int bpos)
{
	int		apos;
	t_stack	*heada;
	t_stack	*headb;

	headb = get_node(*b, bpos);
	headb->to = NULL;
	apos = -1;
	while (++apos < (*a)->len)
	{
		heada = get_node(*a, apos);
		heada->pos = apos;
		if (heada->index > headb->index)
		{
			if (!headb->to)
				headb->to = heada;
			else if (heada->index < headb->to->index)
				headb->to = heada;
		}
	}
	if (!headb->to)
		headb->to = get_node(*a, find_smallest(*a));
	headb->pos = bpos;
}

//set length & median in each element of a & b
void	set_lm(t_stack **a, t_stack **b)
{
	int	a_len;
	int	b_len;

	*b = first_node(*b);
	*a = first_node(*a);
	a_len = list_size(*a);
	b_len = list_size(*b);
	while (*b)
	{
		(*b)->len = b_len;
		(*b)->med = b_len / 2;
		if (!(*b)->next)
			break ;
		(*b) = (*b)->next;
	}
	*b = first_node(*b);
	while (*a)
	{
		(*a)->len = a_len;
		(*a)->med = a_len / 2;
		if (!(*a)->next)
			break ;
		(*a) = (*a)->next;
	}
	*a = first_node(*a);
}

//find where element is in relation to median & determine how many
//moves are needed for each element to reach its target in a
void	set_move(t_stack *a, t_stack **b)
{
	int		i;
	t_stack	*c;

	i = -1;
	while (++i < (*b)->len)
	{
		c = get_node(*b, i);
		if (c->pos <= (*b)->med && c->to->pos > a->med)
			c->mov = c->pos + (a->len - c->to->pos);
		else if (c->pos > (*b)->med && c->to->pos <= a->med)
			c->mov = ((*b)->len - c->pos) + c->to->pos;
		else if (c->pos > (*b)->med && c->to->pos > a->med)
			c->mov = double_rot(((*b)->len - c->pos), \
					(a->len - c->to->pos), SET_MOVE);
		else if (c->pos <= (*b)->med && c->to->pos <= a->med)
			c->mov = double_rot(c->pos, c->to->pos, SET_MOVE);
	}
}

//pointer to the element which needs the least nr of moves to a
int	find_best_option(t_stack *b)
{
	int		place;
	int		least;

	place = b->pos;
	least = b->mov;
	while (b)
	{
		if (b->mov < least)
		{
			least = b->mov;
			place = b->pos;
		}
		b = b->next;
	}
	return (place);
}

//move best option to stack a
void	move_best_option(t_stack **a, t_stack **b, int place)
{
	t_stack	*c;
	int		turn;

	turn = 0;
	c = get_node(*b, place);
	if (c->pos > (*b)->med && c->to->pos > (*a)->med)
	{
		turn = double_rot(((*b)->len - c->pos), ((*a)->len - c->to->pos), MOVE);
		rep_act2(a, b, rrr, turn);
	}
	else if (c->pos <= (*b)->med && c->to->pos <= (*a)->med)
	{
		turn = double_rot(c->pos, c->to->pos, MOVE);
		rep_act2(a, b, rr, turn);
	}
	if (c->pos <= (*b)->med)
		rep_act1(b, rb, (c->pos - turn));
	if (c->pos > (*b)->med)
		rep_act1(b, rrb, ((*b)->len - c->pos - turn));
	if (c->to->pos <= (*a)->med)
		rep_act1(a, ra, (c->to->pos - turn));
	if (c->to->pos > (*a)->med)
		rep_act1(a, rra, ((*a)->len - c->to->pos - turn));
}
