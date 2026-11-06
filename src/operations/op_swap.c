/* ************************************************************************** */
/*                                                                            */
/*    ______      Ficheiro : bench.c
/*   |___  /      Autor    : Alexandro Luamba
/*      / /       Criado   : 06/11/2026
/*     / /        Escola   : 42 Luanda
/*    / /                                                                     */
/*   /_/                                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, t_opts *opts)
{
	t_stack	*primero;
	t_stack	*segundo;

	if (!a || !*a || !(*a)->next)
		return ;
	primero = *a;
	segundo = primero->next;
	primero->next = segundo->next;
	segundo->next = primero;
	*a = segundo;
	write(1, "sa\n", 3);
	if (opts != NULL)
	{
		opts->total_ops++;
		opts->ops_sa++;
	}
}

void	sb(t_stack **b, t_opts *opts)
{
	t_stack	*primero;
	t_stack	*segundo;

	if (!b || !*b || !(*b)->next)
		return ;
	primero = *b;
	segundo = primero->next;
	primero->next = segundo->next;
	segundo->next = primero;
	*b = segundo;
	write(1, "sb\n", 3);
	if (opts != NULL)
	{
		opts->total_ops++;
		opts->ops_sb++;
	}
}

void	ss(t_stack **a, t_stack **b, t_opts *opts)
{
	sa(a, NULL);
	sb(b, NULL);
	write(1, "ss\n", 3);
	if (opts != NULL)
	{
		opts->total_ops++;
		opts->ops_ss++;
	}
}
