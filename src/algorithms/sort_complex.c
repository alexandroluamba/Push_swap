/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateus- <amateus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:27:27 by amateus-          #+#    #+#             */
/*   Updated: 2026/08/31 15:27:28 by amateus-         ###   ########.fr       */
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

void	sort_complex(t_stack **a, t_stack **b)
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
			// Verifica se o bit 'i' do índice é 1 ou 0
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		// Esvazia totalmente B de volta para A
		while (*b)
			pa(a, b);
		i++;
	}
}