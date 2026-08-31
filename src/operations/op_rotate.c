#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*primeiro;
	t_stack *ultimo;

	if (!a || !*a || !(*a)->next)
		return ;
	primeiro = *a;
	*a = (*a)->next;
	primeiro->next = NULL;
	ultimo = ft_lstlast(*a);
	ultimo->next = primeiro;
}

void	rb(t_stack **b)
{
	t_stack	*primeiro;
	t_stack	*ultimo;

	if (!b || !*b || !(*b)->next)
		return ;
	primeiro = *b;
	*b = (*b)->next;
	primeiro->next = NULL;
	ultimo = ft_lstlast(*b);
	ultimo->next = primeiro;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}