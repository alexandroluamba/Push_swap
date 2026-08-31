#include "push_swap.h"

t_stack *build_stack(char **argv, int start, int argc)
{
	t_stack	*a;
	t_stack	*node;
	int		i;

	a = NULL;
	i = argc - 1;
	while (i >= start)
	{
		node = new_node(atoi(argv[i]));
		add_to_top(&a, node);
		i--;
	}
	return (a);
}