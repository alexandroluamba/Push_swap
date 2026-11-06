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

void	pa(t_stack **a, t_stack **b, t_opts *opts)
{
	t_stack	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
	if (opts != NULL)
	{
		opts->total_ops++;
		opts->ops_pa++;
	}
}

void	pb(t_stack **a, t_stack **b, t_opts *opts)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
	if (opts != NULL)
	{
		opts->total_ops++;
		opts->ops_pb++;
	}
}
