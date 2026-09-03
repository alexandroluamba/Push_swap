/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:04:48 by tmachado          #+#    #+#             */
/*   Updated: 2026/09/03 17:54:27 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_strategy(t_stack **a, t_stack **b, t_opts *opts)
{
	if (opts->flag_simple)
		sort_simple(a, b, opts);
	else if (opts->flag_medium)
		sort_medium(a, b, opts);
	else if (opts->flag_complex)
		sort_complex(a, b, opts);
	else
		sort_adaptive(a, b, opts);
}

static t_stack	*init_and_build(int argc, char **argv, t_opts *opts)
{
	t_stack	*a;

	init_opts(opts);
	if (argc < 2)
		return (NULL);
	if (!parse_flags(argc, argv, opts))
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	if (opts->start_index >= argc)
		return (NULL);
	a = build_stack(argv, opts->start_index, argc);
	if (!a)
		ft_putstr_fd("Error\n", 2);
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_opts	opts;
	double	disorder_val;

	b = NULL;
	a = init_and_build(argc, argv, &opts);
	if (!a)
		return (0);
	index_stack(a);
	disorder_val = compute_disorder(a);
	if (!is_sorted(a))
		execute_strategy(&a, &b, &opts);
	if (opts.flag_bench)
		print_bench(&opts, disorder_val);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
