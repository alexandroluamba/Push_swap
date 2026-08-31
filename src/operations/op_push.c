#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void    pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}