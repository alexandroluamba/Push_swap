/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 17:55:44 by tmachado          #+#    #+#             */
/*   Updated: 2026/09/03 18:22:25 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num_valid(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	tem_duplicado(t_stack *a, int n)
{
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}
