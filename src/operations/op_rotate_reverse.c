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
}
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
