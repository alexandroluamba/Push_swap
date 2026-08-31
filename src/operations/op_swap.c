#include "push_swap.h"

void sa(t_stack **a)
{
	t_stack	*primero;
	t_stack	*segundo;

	if (!*a || !(*a)->next)
		return ;
	primero = *a;
	segundo = primero->next;
	primero->next = segundo->next;
	segundo->next = primero;
	*a = segundo;
}

