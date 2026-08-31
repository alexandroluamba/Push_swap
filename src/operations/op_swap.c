#include "push_swap.h"

void sa(t_stack **a)
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
}

void sb(t_stack **b)
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
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
