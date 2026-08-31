/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:23:38 by tmachado          #+#    #+#             */
/*   Updated: 2026/08/31 16:00:16 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*ultimo;
	t_stack *penultimo;

	if (!a || !*a || !(*a)->next)
		return ;
	penultimo = *a;
	while (penultimo->next->next != NULL)
    	penultimo = penultimo->next;
	ultimo = penultimo->next;
	penultimo->next = NULL;
	ultimo->next = *a;
	*a = ultimo;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*ultimo;
	t_stack	*penultimo;

	if (!b || !*b || !(*b)->next)
		return ;
	penultimo = *b;
	while (penultimo->next->next != NULL)
		penultimo = penultimo->next;
	ultimo = penultimo->next;
	penultimo->next = NULL;
	ultimo->next = *b;
	*b = ultimo;
	write(1, "rrb\n", 4);
}
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
