/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateus- <amateus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 15:17:55 by tmachado          #+#    #+#             */
/*   Updated: 2026/08/31 19:05:51 by amateus-         ###   ########.fr       */
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
	int	algo_count;

	opts->flag_simple = 0;
	opts->flag_medium = 0;
	opts->flag_complex = 0;
	opts->flag_adaptive = 0;
	opts->flag_bench = 0;
	opts->total_ops = 0;
	
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
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
			return (0); /* Flag desconhecida -> Error */
		i++;
	}
	opts->start_index = i;

	/* Validação: Não permite mais do que 1 flag de algoritmo ao mesmo tempo */
	algo_count = opts->flag_simple + opts->flag_medium + opts->flag_complex + opts->flag_adaptive;
	if (algo_count > 1)
		return (0); /* Retorna 0 para o main.c imprimir Error\n */

	return (1);
}