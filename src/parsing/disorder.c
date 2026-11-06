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
