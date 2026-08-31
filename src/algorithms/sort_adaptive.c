/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateus- <amateus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:26:45 by amateus-          #+#    #+#             */
/*   Updated: 2026/08/31 20:02:33 by amateus-         ###   ########.fr       */
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
		sort_small(a, b, opts);
		return ;
	}
	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		sort_simple(a, b, opts);
	else if (disorder < 0.5)
		sort_medium(a, b, opts);
	else
		sort_complex(a, b, opts);
}