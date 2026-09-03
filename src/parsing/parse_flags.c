/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:17:55 by tmachado          #+#    #+#             */
/*   Updated: 2026/09/03 21:25:49 by tmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static	void	init_flags(t_opts *opts)
{
	opts->flag_simple = 0;
	opts->flag_medium = 0;
	opts->flag_complex = 0;
	opts->flag_adaptive = 0;
	opts->flag_bench = 0;
	opts->total_ops = 0;
}

static	int	match_flag(char	*arg, t_opts *opts)
{
	if (ft_strcmp(arg, "--simple") == 0)
		opts->flag_simple = 1;
	else if (ft_strcmp(arg, "--medium") == 0)
		opts->flag_medium = 1;
	else if (ft_strcmp(arg, "--complex") == 0)
		opts->flag_complex = 1;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		opts->flag_adaptive = 1;
	else if (ft_strcmp(arg, "--bench") == 0)
		opts->flag_bench = 1;
	else
		return (0);
	return (1);
}

int	parse_flags(int argc, char **argv, t_opts *opts)
{
	int	i;
	int	algo_count;

	init_flags(opts);
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (is_num_valid(argv[i]))
			break ;
		if (!match_flag(argv[i], opts))
			return (0);
		i++;
	}
	opts->start_index = i;
	algo_count = opts->flag_simple + opts->flag_medium
		+ opts->flag_complex + opts->flag_adaptive;
	if (algo_count > 1)
		return (0);
	return (1);
}
