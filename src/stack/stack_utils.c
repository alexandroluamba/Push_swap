/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:04:03 by amateus-          #+#    #+#             */
/*   Updated: 2026/08/31 15:49:31 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/* Atribui a cada elemento um índice de 0 a (N - 1) com base no seu valor */
void	index_stack(t_stack *a)
{
	t_stack	*current;
	t_stack	*compare;
	int		idx;

	current = a;
	while (current)
	{
		idx = 0;
		compare = a;
		while (compare)
		{
			if (compare->value < current->value)
				idx++;
			compare = compare->next;
		}
		current->index = idx;
		current = current->next;
	}
}

/* Calcula o grau de desordem D (0.0 = totalmente ordenada, 1.0 = invertida) */


int	find_max_pos(t_stack *stack)
{
	int		max_val;
	int		max_pos;
	int		current_pos;
	t_stack	*tmp;

	if (!stack)
		return (0);
	max_val = stack->value;
	max_pos = 0;
	current_pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value > max_val)
		{
			max_val = tmp->value;
			max_pos = current_pos;
		}
		current_pos++;
		tmp = tmp->next;
	}
	return (max_pos);
}