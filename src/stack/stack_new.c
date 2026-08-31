#include "push_swap.h"

t_stack *new_node(int value)
{
	t_stack *new_node;
	
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);

}