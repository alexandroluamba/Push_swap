/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_to_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:24:42 by tmachado          #+#    #+#             */
/*   Updated: 2026/08/31 22:43:29 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_top(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;
	node->next = *stack;
	*stack = node;
}
