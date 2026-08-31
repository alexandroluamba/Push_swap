/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateus- <amateus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:27:03 by amateus-          #+#    #+#             */
/*   Updated: 2026/08/31 19:57:31 by amateus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_stack **a, t_stack **b, int chunk_size, t_opts *opts)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, opts);
			rb(b, opts);
			i++;
		}
		else if ((*a)->index <= (i + chunk_size))
		{
			pb(a, b, opts);
			i++;
		}
		else
			ra(a, opts);
	}
}

void	sort_medium(t_stack **a, t_stack **b, t_opts *opts)
{
	int	size;
	int	chunk_size;
	int	max_pos;

	size = stack_size(*a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks_to_b(a, b, chunk_size, opts);
	while (*b)
	{
		max_pos = find_max_pos(*b); // Reaproveita ou busca o maior índice em B
		// Traz o maior elemento de B para o topo e devolve a A
		size = stack_size(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(b, opts);
		}
		else
		{
			while (max_pos++ < size)
				rrb(b, opts);
		}
		pa(a, b, opts);
	}
}