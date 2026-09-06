/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateus- <amateus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:03:28 by amateus-          #+#    #+#             */
/*   Updated: 2026/09/06 18:45:36 by amateus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_and_push(t_stack **a, char *str)
{
	long	num;

	if (!is_num_valid(str))
		return (0);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (tem_duplicado(*a, (int)num))
		return (0);
	add_to_top(a, new_node((int)num));
	return (1);
}

static int	process_split_args(t_stack **a, char **split_args)
{
	int	j;

	if (!split_args || !split_args[0])
		return (free_matrix(split_args), 0);
	j = 0;
	while (split_args[j])
		j++;
	j--;
	while (j >= 0)
	{
		if (split_args[j][0] == '-' && split_args[j][1] == '-')
		{
			j--;
			continue ;
		}
		if (!parse_and_push(a, split_args[j]))
			return (free_matrix(split_args), 0);
		j--;
	}
	free_matrix(split_args);
	return (1);
}

t_stack	*build_stack(char **argv, int start, int argc)
{
	t_stack	*a;
	char	**split_args;
	int		i;

	a = NULL;
	i = argc - 1;
	while (i >= start)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			i--;
			continue ;
		}
		split_args = ft_split(argv[i], ' ');
		if (!process_split_args(&a, split_args))
		{
			free_stack(&a);
			return (NULL);
		}
		i--;
	}
	return (a);
}
