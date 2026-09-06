/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateus- <amateus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:39:56 by tmachado          #+#    #+#             */
/*   Updated: 2026/09/06 18:41:58 by amateus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_opts
{
	int	flag_simple;
	int	flag_medium;
	int	flag_complex;
	int	flag_adaptive;
	int	flag_bench;
	int	start_index;
	int	total_ops;
	int	adaptive_used;
	int	ops_sa;
	int	ops_sb;
	int	ops_ss;
	int	ops_pa;
	int	ops_pb;
	int	ops_ra;
	int	ops_rb;
	int	ops_rr;
	int	ops_rra;
	int	ops_rrb;
	int	ops_rrr;
}	t_opts;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack			*new_node(int value);
void			add_to_top(t_stack **stack, t_stack *node);
int				stack_size(t_stack *stack);
int				parse_flags(int argc, char **argv, t_opts *opts);
int				is_num_valid(char *str);
int				tem_duplicado(t_stack *a, int n);
long			ft_atol(const char *str);
t_stack			*build_stack(char **argv, int start, int argc);
t_stack			*ft_lstlast(t_stack *lst);
void			sa(t_stack **a, t_opts *opts);
void			sb(t_stack **b, t_opts *opts);
void			ss(t_stack **a, t_stack **b, t_opts *opts);
void			pa(t_stack **a, t_stack **b, t_opts *opts);
void			pb(t_stack **a, t_stack **b, t_opts *opts);
void			ra(t_stack **a, t_opts *opts);
void			rb(t_stack **b, t_opts *opts);
void			rr(t_stack **a, t_stack **b, t_opts *opts);
void			rra(t_stack **a, t_opts *opts);
void			rrb(t_stack **b, t_opts *opts);
void			rrr(t_stack **a, t_stack **b, t_opts *opts);
void			index_stack(t_stack *a);
double			compute_disorder(t_stack *a);
void			sort_simple(t_stack **a, t_stack **b, t_opts *opts);
void			sort_medium(t_stack **a, t_stack **b, t_opts *opts);
void			sort_complex(t_stack **a, t_stack **b, t_opts *opts);
void			sort_adaptive(t_stack **a, t_stack **b, t_opts *opts);
void			sort_three(t_stack **a, t_opts *opts);
void			sort_small(t_stack **a, t_stack **b, t_opts *opts);
void			free_stack(t_stack **stack);
void			free_matrix(char **lst);
char			**ft_split(char const *s, char c);
int				is_sorted(t_stack *stack);
int				find_max_pos(t_stack *stack);
void			print_bench(t_opts *opts, double disorder_val);
const char		*get_strategy_name(t_opts *opts);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			init_opts(t_opts *opts);

#endif
