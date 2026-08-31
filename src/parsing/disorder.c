/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:50:03 by tmachado          #+#    #+#             */
/*   Updated: 2026/08/31 22:32:16 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	long	inversions;
	long	total_pairs;

	if (!a || !a->next)
		return (0.0);
	inversions = 0;
	total_pairs = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				inversions++;
			total_pairs++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)inversions / (double)total_pairs);
}
