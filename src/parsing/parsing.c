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

t_stack	*build_stack(char **argv, int start, int argc)
{
	t_stack	*a;
	t_stack	*node;
	int		i;
	long	num;

	a = NULL;
	i = argc - 1;
	while (i >= start)
	{
		if (!is_num_valid(argv[i]))
		{
			free_stack(&a);
			write(2, "Error\n", 6);
			return (NULL);
		}
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX || tem_duplicado(a, (int)num))
		{
			free_stack(&a);
			write(2, "Error\n", 6);
			return (NULL);
		}
		
		node = new_node((int)num);
		if (!node)
		{
			free_stack(&a);
			return (NULL);
		}
		add_to_top(&a, node);
		i--;
	}
	return (a);
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