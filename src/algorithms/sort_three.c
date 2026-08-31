#include "push_swap.h"

static int	find_max(t_stack *a)
{
	int	max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

void	sort_three(t_stack **a)
{
	int	max;

	if (is_sorted(*a))
		return ;
	max = find_max(*a);
	if ((*a)->value == max)
		ra(a);
	else if ((*a)->next->value == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}