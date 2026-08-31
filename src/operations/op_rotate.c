/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:16:31 by tmachado          #+#    #+#             */
/*   Updated: 2026/08/31 15:59:42 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack **a)
{
	t_stack	*primeiro;
	t_stack *ultimo;

	if (!a || !*a || !(*a)->next)
		return ;
	primeiro = *a;
	*a = (*a)->next;
	primeiro->next = NULL;
	ultimo = ft_lstlast(*a);
	ultimo->next = primeiro;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*primeiro;
	t_stack	*ultimo;

	if (!b || !*b || !(*b)->next)
		return ;
	primeiro = *b;
	*b = (*b)->next;
	primeiro->next = NULL;
	ultimo = ft_lstlast(*b);
	ultimo->next = primeiro;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
