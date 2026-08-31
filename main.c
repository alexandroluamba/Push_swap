/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:04:48 by tmachado          #+#    #+#             */
/*   Updated: 2026/08/31 15:32:48 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_strategy(t_stack **a, t_stack **b, t_opts *opts)
{
	if (opts->flag_simple)
		sort_simple(a, b);
	else if (opts->flag_medium)
		sort_medium(a, b);
	else if (opts->flag_complex)
		sort_complex(a, b);
	else
		sort_adaptive(a, b); /* Padrão (Adaptive) */
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_opts	opts;

	if (argc < 2)
		return (0);
	if (!parse_flags(argc, argv, &opts))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (opts.start_index >= argc)
		return (0);
	a = build_stack(argv, opts.start_index, argc);
	if (!a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	b = NULL;
	index_stack(a);
	if (!is_sorted(a))
		execute_strategy(&a, &b, &opts);
	free_stack(&a);
	free_stack(&b);
	return (0);
}