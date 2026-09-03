/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:26:45 by amateus-          #+#    #+#             */
/*   Updated: 2026/09/03 21:29:51 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_by_disorder(t_stack **a, t_stack **b,
	t_opts *opts, double disorder)
{
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
		opts->adaptive_used = 3;
		sort_complex(a, b, opts);
	}
}

void	sort_adaptive(t_stack **a, t_stack **b, t_opts *opts)
{
	double	disorder;

	if (!a || !*a || is_sorted(*a))
		return ;
	if (stack_size(*a) <= 5)
	{
		opts->adaptive_used = 0;
		sort_small(a, b, opts);
		return ;
	}
	disorder = compute_disorder(*a);
	run_by_disorder(a, b, opts, disorder);
}
