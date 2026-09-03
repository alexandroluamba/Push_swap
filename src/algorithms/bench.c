/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 22:00:17 by tmachado          #+#    #+#             */
/*   Updated: 2026/09/03 21:32:22 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder_pct(double disorder)
{
	int	pct_int;
	int	pct_dec;

	pct_int = (int)(disorder * 100);
	pct_dec = (int)(disorder * 10000) % 100;
	ft_putnbr_fd(pct_int, 2);
	ft_putstr_fd(".", 2);
	if (pct_dec < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(pct_dec, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_ops_group1(t_opts *opts)
{
	ft_putstr_fd("[bench] sa:  ", 2);
	ft_putnbr_fd(opts->ops_sa, 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(opts->ops_sb, 2);
	ft_putstr_fd("  ss:  ", 2);
	ft_putnbr_fd(opts->ops_ss, 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(opts->ops_pa, 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(opts->ops_pb, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_ops_group2(t_opts *opts)
{
	ft_putstr_fd("[bench] ra:  ", 2);
	ft_putnbr_fd(opts->ops_ra, 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(opts->ops_rb, 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(opts->ops_rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(opts->ops_rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(opts->ops_rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(opts->ops_rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_opts *opts, double disorder_val)
{
	ft_putstr_fd("[bench] disorder:  ", 2);
	print_disorder_pct(disorder_val);
	ft_putstr_fd("[bench] strategy:  ", 2);
	ft_putstr_fd((char *)get_strategy_name(opts), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(opts->total_ops, 2);
	ft_putstr_fd("\n", 2);
	print_ops_group1(opts);
	print_ops_group2(opts);
}
