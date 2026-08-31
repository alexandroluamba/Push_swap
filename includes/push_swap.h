/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:25:04 by tmachado          #+#    #+#             */
/*   Updated: 2026/08/31 14:25:05 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
}   t_stack;

t_stack	*new_node(int value);
void	add_to_top(t_stack **stack, t_stack *node);
int		stack_size(t_stack *stack);
int		is_num_valid(char *str);
int		tem_duplicado(t_stack *a, int n);
long	atol(const char *str);
void	print_stack(t_stack *stack);
t_stack	*build_stack(char **argv, int start, int argc);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
