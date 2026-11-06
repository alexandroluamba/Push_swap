/* ************************************************************************** */
/*                                                                            */
/*    ______      Ficheiro : bench.c
/*   |___  /      Autor    : Alexandro Luamba
/*      / /       Criado   : 06/11/2026
/*     / /        Escola   : 42 Luanda
/*    / /                                                                     */
/*   /_/                                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_opts(t_opts *opts)
{
	if (!opts)
		return ;
	opts->flag_bench = 0;
	opts->flag_simple = 0;
	opts->flag_medium = 0;
	opts->flag_complex = 0;
	opts->flag_adaptive = 0;
	opts->adaptive_used = 0;
	opts->start_index = 1;
	opts->total_ops = 0;
	opts->ops_sa = 0;
	opts->ops_sb = 0;
	opts->ops_ss = 0;
	opts->ops_pa = 0;
	opts->ops_pb = 0;
	opts->ops_ra = 0;
	opts->ops_rb = 0;
	opts->ops_rr = 0;
	opts->ops_rra = 0;
	opts->ops_rrb = 0;
	opts->ops_rrr = 0;
}
