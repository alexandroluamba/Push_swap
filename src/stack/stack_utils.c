#include "push_swap.h"

int stack_size(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}