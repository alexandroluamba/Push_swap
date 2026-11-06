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

void	rra(t_stack **a, t_opts *opts)
{
	t_stack	*ultimo;
	t_stack	*penultimo;

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
	if (opts != NULL)
	{
		opts->total_ops++;
		opts->ops_rra++;
	}
}

void	rrb(t_stack **b, t_opts *opts)
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
	if (opts != NULL)
	{
		opts->total_ops++;
		opts->ops_rrb++;
	}
}

void	rrr(t_stack **a, t_stack **b, t_opts *opts)
{
	rra(a, NULL);
	rrb(b, NULL);
	write(1, "rrr\n", 4);
	if (opts != NULL)
	{
		opts->total_ops++;
		opts->ops_rrr++;
	}
}
