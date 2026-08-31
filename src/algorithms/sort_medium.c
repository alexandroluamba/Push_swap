/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateus- <amateus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:27:03 by amateus-          #+#    #+#             */
/*   Updated: 2026/08/31 15:27:04 by amateus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sqrt(int number)
{
	int	i;

	if (number <= 0)
		return (0);
	i = 1;
	while (i * i <= number)
		i++;
	return (i - 1);
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, int chunk_size)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= (i + chunk_size))
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

void	sort_medium(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;
	int	max_pos;

	size = stack_size(*a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks_to_b(a, b, chunk_size);
	while (*b)
	{
		max_pos = find_min_pos(*b); // Reaproveita ou busca o maior índice em B
		// Traz o maior elemento de B para o topo e devolve a A
		size = stack_size(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			while (max_pos++ < size)
				rrb(b);
		}
		pa(a, b);
	}
}