/* ************************************************************************** */
/*                                                                            */
/*    ______      Ficheiro : stack_add_to_top.c
/*   |___  /      Autor    : Alexandro Luamba
/*      / /       Criado   : 06/11/2026
/*     / /        Escola   : 42 Luanda
/*    / /                                                                     */
/*   /_/                                                                      */
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
