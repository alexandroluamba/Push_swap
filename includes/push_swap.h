/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:39:56 by tmachado          #+#    #+#             */
/*   Updated: 2026/08/31 16:21:11 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <limits.h>

typedef struct s_opts
{
	int	flag_simple;
	int	flag_medium;
	int	flag_complex;
	int	flag_adaptive;
	int	flag_bench;
	int	start_index; /* Indica em que índice de argv começam os números */
}	t_opts;

/* Protótipo da função de parsing de flags */

typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
}   t_stack;

t_stack	*new_node(int value);
void	add_to_top(t_stack **stack, t_stack *node);
int		stack_size(t_stack *stack);
int	parse_flags(int argc, char **argv, t_opts *opts);
int		is_num_valid(char *str);
int		tem_duplicado(t_stack *a, int n);
long	atol(const char *str);
void	print_stack(t_stack *stack);
t_stack	*build_stack(char **argv, int start, int argc);
t_stack	*ft_lstlast(t_stack *lst);
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
void	index_stack(t_stack *a);
double	compute_disorder(t_stack *a);
void	sort_simple(t_stack **a, t_stack **b);
void	sort_medium(t_stack **a, t_stack **b);
void	sort_complex(t_stack **a, t_stack **b);
void	sort_adaptive(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_small(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);
void	free_matrix(char **lst);
char	**ft_split(char const *s, char c);
int		is_sorted(t_stack *stack);
int		find_max_pos(t_stack *stack);

#endif
