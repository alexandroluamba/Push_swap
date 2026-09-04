/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:26:45 by amateus-          #+#    #+#             */
/*   Updated: 2026/09/04 15:17:22 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack **a, t_stack **b, t_opts *opts)
{
	double	disorder;

	if (!a || !*a || is_sorted(*a))
		return ;
	if (stack_size(*a) <= 5)
	{
		opts->adaptive_used = 1;
		sort_small(a, b, opts);
		return ;
	}
	disorder = compute_disorder(*a);
	if (disorder < 0.2)
	{
		opts->adaptive_used = 1;
		sort_simple(a, b, opts);
	}
	else if (disorder < 0.5)
	{
		opts->adaptive_used = 2;
		sort_medium(a, b, opts);
	}
	else
	{
		sort_complex(a, b, opts);
	}
}

const char	*get_strategy_name(t_opts *opts)
{
	if (opts->flag_simple)
		return ("Simple / O(n^2)");
	if (opts->flag_medium)
		return ("Medium / O(n√n)");
	if (opts->flag_complex)
		return ("Complex / O(n log n)");
	if (opts->adaptive_used == 1)
		return ("Adaptive / O(n^2)");
	if (opts->adaptive_used == 1)
		return ("Adaptive / O(n^2)");
	if (opts->adaptive_used == 2)
		return ("Adaptive / O(n√n)");
	return ("Adaptive (complex) / O(n log n)");
}
