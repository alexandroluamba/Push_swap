/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmachado <tmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:17:55 by tmachado          #+#    #+#             */
/*   Updated: 2026/08/31 15:32:27 by tmachado         ###   ########.fr       */
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

int	parse_flags(int argc, char **argv, t_opts *opts)
{
	int	i;

	opts->flag_simple = 0;
	opts->flag_medium = 0;
	opts->flag_complex = 0;
	opts->flag_adaptive = 0;
	opts->flag_bench = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		/* Se for apenas um número negativo (ex: -5), interrompe a busca de flags */
		if (is_num_valid(argv[i]))
			break ;
		if (ft_strcmp(argv[i], "--simple") == 0)
			opts->flag_simple = 1;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			opts->flag_medium = 1;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			opts->flag_complex = 1;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			opts->flag_adaptive = 1;
		else if (ft_strcmp(argv[i], "--bench") == 0)
			opts->flag_bench = 1;
		else
			return (0); /* Flag inválida */
		i++;
	}
	opts->start_index = i;
	return (1);
}