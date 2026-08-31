/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateus- <amateus-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 14:03:28 by amateus-          #+#    #+#             */
/*   Updated: 2026/08/31 17:18:32 by amateus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sinal;
	long	resultado;

	i = 0;
	sinal = 1;
	resultado = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sinal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultado = (resultado * 10) + (str[i] - '0');
		i++;
	}
	return (resultado * sinal);
}

int		is_num_valid(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);

}

int	tem_duplicado(t_stack *a, int n)
{
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/* Função auxiliar para converter, validar e inserir cada token na pilha */
static int	parse_and_push(t_stack **a, char *str)
{
	long	num;

	if (!is_num_valid(str))
		return (0);
	num = atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (tem_duplicado(*a, (int)num))
		return (0);
	add_to_top(a, new_node((int)num));
	return (1);
}

t_stack *build_stack(char **argv, int start, int argc)
{
    t_stack *a;
    char    **split_args;
    int     i;
    int     j;

    a = NULL;
    i = argc - 1; /* Começa no último argumento do terminal */
    while (i >= start)
    {
        split_args = ft_split(argv[i], ' ');
        if (!split_args || !split_args[0])
        {
            free_matrix(split_args);
            free_stack(&a);
            return (NULL);
        }
        
        /* Conta quantos elementos existem no split para ir também do último ao primeiro */
        j = 0;
        while (split_args[j])
            j++;
        j--;
        
        while (j >= 0)
        {
            if (!parse_and_push(&a, split_args[j]))
            {
                free_matrix(split_args);
                free_stack(&a);
                return (NULL);
            }
            j--;
        }
        
        free_matrix(split_args);
        i--;
    }
    return (a);
}