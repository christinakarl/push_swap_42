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

int	check_input(char **tab)
{
	int	i;
	int	j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == ' ' || ft_isdigit(tab[j][i]) == 1 || tab[j][i] == '-' || tab[j][i] == '+')
				i++;
			else
				return (1);
		}
		j++;
	}
	return (0);
}



int	main(int argc, char **argv)
{
	//1. check if argv is one string with different numbers or multiple argv & if multiple check each
	// argv if it is string (using strchr) > if mix "Error\n"
	// already check for other char (digit, -, +, ' '), otherwise "Error\n"
	char	**input_tab;

	if (argc < 2) //no parameters
		return (ft_printf("Error\n"));
	if (ft_strchr(argv[1], ' ') != NULL)
	{
		if (argc > 2) //mix of strings and int (if string is first)
			return (ft_printf("Error\n"));
		input_tab = ft_split(argv[1], ' ');
		if (check_input(input_tab) == 1) //other characters
			return (ft_printf("Error\n"));
	}



	//2. if one string > ft_split, if separate argv, use **argv to create **tab of int (atoi)
	//check for following errors: >int max || <int min, only -- || ++ without digits

	//3. check for duplicates >> compare each element with all following elements, if dupl > "Error\n"

	//if list length == 1, return without any actions


	return (0);
}
