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
		headb->target = NULL;
		apos = -1;
		while (++apos < list_size(*a))
		{
			heada = get_node(*a, apos);
			if (!heada->pos)
				heada->pos = apos;
			if (heada->index > headb->index)
			{
				if (!headb->target)
					headb->target = heada;
				else if (heada->index < headb->target->index)
					headb->target = heada;
			}
		}
	if (!headb->target)
		headb->target = *a;
	headb->pos = bpos;
	}
}


//find where element is in relation to median & determine how many actions are needed for each element
int	set_move(t_stack **a, t_stack **b)
{
	int amed;
	int	bmed;

	amed = list_size(*a) / 2;
	bmed = list_size(*b) / 2;
	//find how to determine how many moves it takes: test if both b & target are above or below median >> rr or rrr would be possible

}

//move the element which needs the least nr of moves to a
void	find_move(t_stack **a, t_stack **b)
{

}

//algo for >5 elements: 1. push all to b except of 3, 2. algo_three,
// 3. find target_nodes for all of b nodes, 4. check which one can be moved most easily (least operations)
// 5. move it, 6. repeat until !*b
void	algo_more(t_stack **a, t_stack **b)
{
	int	len;
	t_stack	*temp;

	len = list_size(*a);
	while (len > 3)
	{
		pb(a, b);
		len--;
	}
	algo_three(a);
	set_tp(a, b);
	temp = *b;
	while (temp)
	{
		//find target node for all of b, set positions
		if (temp->target)
			ft_printf("b's target: %d\n", temp->target->content);
		ft_printf("b's position: %d, index: %d\n", temp->pos,temp->index);
		temp = temp->next;
		//check which one is moved most easily, depending on if element is above or below median (both b and target)

		//move it && compare first to second (if first is bigger > ra)
	}
}
