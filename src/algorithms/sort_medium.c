/* ************************************************************************** */
/*                                                                            */
/*    ______      Ficheiro : bench.c
/*   |___  /      Autor    : Alexandro Luamba
/*      / /       Criado   : 06/11/2026
/*     / /        Escola   : 42 Luanda
/*    / /                                                                     */
/*   /_/                                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_stack **a, t_stack **b,
	int chunk_size, t_opts *opts)
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

static void	merge_back(t_stack **a, t_stack **b, t_opts *opts)
{
	int	max_pos;
	int	size;

	while (*b)
	{
		max_pos = find_max_pos(*b);
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

void	sort_medium(t_stack **a, t_stack **b, t_opts *opts)
{
	int	size;
	int	chunk_size;

	size = stack_size(*a);
	if (size <= 100)
		chunk_size = 19;
	else
		chunk_size = 45;
	push_chunks_to_b(a, b, chunk_size, opts);
	merge_back(a, b, opts);
}
