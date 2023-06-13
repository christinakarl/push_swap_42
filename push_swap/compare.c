/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/05/06 15:04:21 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if list is sorted in ascending order
int	check_order(t_stack *list)
{
	while (list->next)
	{
		if (list->next->index < list->index)
			return (1);
		else
			list = list->next;
	}
	return (0);
}

//check if list is sorted in descending order
int	check_reverse_order(t_stack *list)
{
	while (list->next)
	{
		if (list->next->index > list->index)
			return (1);
		else
			list = list->next;
	}
	return (0);
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

//redirect to the right algorithm depending on length
void	direct_algo(t_stack **a, t_stack **b)
{
	int	len;

	len = list_size(*a);
	if (len == 1 || check_order(*a) == 0) //check if list is already sorted
		return ;
	else if (len == 2)
		sa(a);
	else if (len == 3)
		algo_three(a);
	else if (len <= 5)
		algo_five(a, b);
	else if (check_reverse_order(*a) == 0 && len > 5) //might not work with larger lists, tbd
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

//set target for b and position for a & b
void	set_tp(t_stack **a, t_stack **b)
{
	int		apos;
	int		bpos;
	t_stack	*heada;
	t_stack	*headb;

	bpos = -1;
	while (++bpos < list_size(*b))
	{
		headb = get_node(*b, bpos);
		headb->to = NULL;
		apos = -1;
		while (++apos < list_size(*a))
		{
			heada = get_node(*a, apos);
			if (!heada->pos)
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
		headb->to = *a;
	headb->pos = bpos;
	}
}

//set length & median in each list element of a & b
void	set_lm(t_stack **a, t_stack **b)
{
	int	a_len;
	int	b_len;

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

//find where element is in relation to median & determine how many moves are needed for each element to reach its to in a
void	set_move(t_stack *a, t_stack **b)
{
	int		i;
	t_stack	*c;

	i = 0;
	while (i < (*b)->len)
	{
		c = get_node(*b, i);
		if (c->pos <= (*b)->med && c->to->pos > a->med)
			c->mov = c->pos + (a->len - c->to->pos);
		else if (c->pos > (*b)->med && c->to->pos <= a->med)
			c->mov = ((*b)->len - c->pos) + c->to->pos;
		else if (c->pos > (*b)->med && c->to->pos > a->med)
		{
			if (((*b)->len - c->pos) > (a->len - c->to->pos))
				c->mov = (((*b)->len - c->pos) - (a->len - c->to->pos)) * 2;
			else if (((*b)->len - c->pos) < (a->len - c->to->pos))
				c->mov = ((a->len - c->to->pos) - ((*b)->len - c->pos)) * 2;
			else if (((*b)->len - c->pos) == (a->len - c->to->pos))
				c->mov = (*b)->len - c->pos;
		}
		else if (c->pos <= (*b)->med && c->to->pos <= a->med)
		{
			if (c->pos < c->to->pos)
				c->mov = c->to->pos;
			else
				c->mov = c->pos;
		}
		i++;
	}
}

//pointer to the element which needs the least nr of movs to a
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

//repeat a rotate/swap/push action multiple times
void	rep_act(t_stack **a, t_stack **b, void (*act)(t_stack **, t_stack **), int rep)
{
	while (rep > 0)
	{
		act(a, b);
		rep--;
	}
}

//repeat a rotate/swap/push action multiple times, only one stack
void	rep_act2(t_stack **x, void (*act)(t_stack **), int rep)
{
	while (rep > 0)
	{
		act(x);
		rep--;
	}
}

//find out how many double rotations are needed based on length & position
int	nbr_rot(int x, int y)
{
	int	nb;

	nb = 0;
	if (x > y)
		nb = x - y;
	else if (x < y)
		nb = y - x;
	else
		nb = x;
	return (nb);
}

//mov best option to stack a
void	move_best_option(t_stack **a, t_stack **b, int place)
{
	t_stack	*c;
	int		turn;

	turn = 0;
	c = get_node(*b, place);
	ft_printf("c->pos: %d & c->to->pos: %d\n", c->pos, c->to->pos);
	if (c->pos > (*b)->med && c->to->pos > (*a)->med)
	{
		turn = nbr_rot(((*b)->len - c->pos), ((*a)->len - c->to->pos));
		rep_act(a, b, rrr, turn);
	}
	else if (c->pos <= (*b)->med && c->to->pos <= (*a)->med)
	{
		if (c->pos < c->to->pos)
			turn = c->pos;
		else
			turn = c->to->pos;
		rep_act(a, b, rr, turn);
	}
	if (c->pos <= (*b)->med)
		rep_act2(b, rb, (c->pos - turn));
	else if (c->pos > (*b)->med)
		rep_act2(b, rrb, ((*b)->len - c->pos - turn));
	if (c->to->pos <= (*a)->med)
		rep_act2(a, ra, (c->to->pos - turn));
	else if (c->to->pos > (*a)->med)
		rep_act2(a, rra, ((*a)->len - c->to->pos - turn));
}

//algo for >5 elements: 1. push all to b except of 3, 2. algo_three,
// 3. find to_nodes for all of b nodes, 4. check which one can be movd most easily (least operations)
// 5. mov it, 6. repeat until !*b
void	algo_more(t_stack **a, t_stack **b)
{
	int	len;
	t_stack	*temp;
	int	best_option = 0;

	len = list_size(*a);
	while (len > 3)
	{
		pb(a, b);
		len--;
	}
	algo_three(a);
	// set_tp(a, b);
	// set_lm(a, b);
	// set_move(*a, b);
	// best_option = find_best_option(*b);

	// ft_printf("best option: %d\n", best_option);
	// move_best_option(a, b, best_option);


	temp = *b;
	while (*b)										//leaves only 2 nbr in a in the end
	{
		set_tp(a, b);
		set_lm(a, b);
		ft_printf("median: %d & length: %d\n", (*b)->med, (*b)->len);
		set_move(*a, b);
		if (temp->to)
		ft_printf("b's target: %d cont: %d, index: %d, nr of movs necessary: %d\n", temp->to->cont, temp->cont,temp->index, temp->mov);
		temp = temp->next;
		best_option = find_best_option(*b);
		move_best_option(a, b, best_option);
		pa(a, b);



	}
}


//from move_best_option
	// if (c->pos <= (*b)->med && c->to->pos > (*a)->med)
	// {
	// 	rep_act2(b, rb, c->pos);
	// 	rep_act2(a, rra, ((*a)->len - c->to->pos));
	// 	ft_printf("first condition\n");
	// }
	// else if (c->pos > (*b)->med && c->to->pos <= (*a)->med)
	// {
	// 	rep_act2(b, rrb, ((*b)->len - c->pos));
	// 	rep_act2(a, ra, c->to->pos);
	// }

			// if (((*b)->len - c->pos) > ((*a)->len - c->to->pos))
		// 	turn = ((*b)->len - c->pos) - ((*a)->len - c->to->pos);
		// else if (((*b)->len - c->pos) < ((*a)->len - c->to->pos))
		// 	turn = ((*a)->len - c->to->pos) - ((*b)->len - c->pos);
		// else if (((*b)->len - c->pos) == ((*a)->len - c->to->pos))
		// 	turn = (*b)->len - c->pos;

			// if ((*a)->pos != 0 && (*b)->pos != 0)
	// 	set_lm(a, b);