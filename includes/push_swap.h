#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int             value;   // o número
    int             index;   // posição normalizada 0..n-1 (usamos mais tarde)
    struct s_stack  *next;   // próximo nó (lista simples)
}   t_stack;

t_stack *new_node(int value);
void add_to_top(t_stack **stack, t_stack *node);
int stack_size(t_stack *stack);
void print_stack(t_stack *stack);
t_stack *build_stack(char **argv, int start, int argc);

#endif
