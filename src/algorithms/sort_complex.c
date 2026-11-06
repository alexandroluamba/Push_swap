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

static int	get_max_bits(t_stack *a)
{
	t_stack	*tmp;
	int		max_index;
	int		max_bits;

	tmp = a;
	max_index = tmp->index;
	while (tmp)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	max_bits = 0;
	while ((max_index >> max_bits) > 0)
		max_bits++;
	return (max_bits);
}

void	sort_complex(t_stack **a, t_stack **b, t_opts *opts)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a, opts);
			else
				pb(a, b, opts);
			j++;
		}
		while (*b)
			pa(a, b, opts);
		i++;
	}
}
