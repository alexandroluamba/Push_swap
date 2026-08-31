/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateus- <amateus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:27:08 by amateus-          #+#    #+#             */
/*   Updated: 2026/08/31 15:27:09 by amateus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *a)
{
	t_stack	*tmp;
	int		min_idx;
	int		pos;
	int		min_pos;

	tmp = a;
	min_idx = tmp->index;
	pos = 0;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->index < min_idx)
		{
			min_idx = tmp->index;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

void	sort_simple(t_stack **a, t_stack **b)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	while (size > 3)
	{
		min_pos = find_min_pos(*a);
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				ra(a);
		}
		else
		{
			while (min_pos++ < size)
				rra(a);
		}
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}