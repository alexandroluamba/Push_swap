/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:07:41 by tmachado          #+#    #+#             */
/*   Updated: 2026/08/31 22:14:11 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *a)
{
	int		min_val;
	int		min_pos;
	int		pos;
	t_stack	*tmp;

	if (!a)
		return (0);
	min_val = a->value;
	min_pos = 0;
	pos = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

static void	sort_three_by_val(t_stack **a, t_opts *opts)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, opts);
	else if (first > second && second > third)
	{
		sa(a, opts);
		rra(a, opts);
	}
	else if (first > second && second < third && first > third)
		ra(a, opts);
	else if (first < second && second > third && first < third)
	{
		sa(a, opts);
		ra(a, opts);
	}
	else if (first < second && second > third && first > third)
		rra(a, opts);
}

void	sort_small(t_stack **a, t_stack **b, t_opts *opts)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	if (size == 2 && (*a)->value > (*a)->next->value)
	{
		sa(a, opts);
		return ;
	}
	if (size == 3)
	{
		sort_three_by_val(a, opts);
		return ;
	}
	while (stack_size(*a) > 3)
	{
		min_pos = find_min_pos(*a);
		size = stack_size(*a);
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				ra(a, opts);
		}
		else
		{
			while (min_pos++ < size)
				rra(a, opts);
		}
		pb(a, b, opts);
	}
	sort_three_by_val(a, opts);
	while (*b)
		pa(a, b, opts);
}
