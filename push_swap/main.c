/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/05/06 15:04:21 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	clear_list(t_stack **list)
{
	t_stack	*next;

	while (*list != NULL)
	{
		next = (*list)->next;
		// free((*list)->content);
		free(*list);
		(*list) = next;
	}
	*list = NULL;
}

//free allocated memory
void	clear_all(char **tab, t_stack **list)
{
	clear_tab(tab);
	clear_list(list);
}

int	main(int argc, char **argv)
{
//done: check if argv is one string with different numbers or multiple argv & if multiple check each
//done: argv if it is string (using strchr) > if mix "Error\n"
	char	**tab;
	t_stack	*a = NULL;
	t_stack	*b = NULL;

	if (argc < 2) //no parameters
		return (ft_printf("Error\n"));
	if (ft_strchr(argv[1], ' ') != NULL) //first argv is a string
	{
		if (argc > 2) //mix of strings and int (if string is first)
			return (ft_printf("Error\n"));
		tab = ft_split(argv[1], ' ');
	}
	else
		tab = input_tab(argv, argc);
//done: already check for other char (digit, -, +, ' '), otherwise "Error\n"
	if (check_input(tab) == 1)
	{
		clear_tab(tab);
		return (ft_printf("Error\n"));
	}
//done: check for duplicates >> compare each element with all following elements, beware of case 4 & 04 if dupl > "Error\n"
//done: create list of int (atoi)
//done: check for >int max || <int min
	if (new_list(&a, tab) == 1 || check_dupl(&a) == 1)
	{
		clear_all(tab, &a);
		return (ft_printf("Error\n"));
	}
//done: create b list, bubble sort, transform a with b numbers
	new_list(&b, tab);
	bubble_sort(&b);
	index_list(&a, b);
	clear_list(&b);
//done: create prev pointers, b list should be empty

	direct_algo(&a, &b);

	ft_printf("a: ");
	while (a)
	{
		ft_printf("%d ", (a->content));
		a = a->next;
	}
	ft_printf("\n");
	ft_printf("b: ");
	while (b)
	{
		ft_printf("%d ", (b->content));
		b = b->next;
	}
	ft_printf("\n");
//done: create all action functions

//redirect to right algo


	clear_all(tab, &a);
	clear_list(&b);
	// exit(0); doesn't really avoid leaks here
	return (0);
}
