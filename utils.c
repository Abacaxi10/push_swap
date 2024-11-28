/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:50:45 by rabatist          #+#    #+#             */
/*   Updated: 2024/11/28 15:54:32 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_numbers(t_stacks *s)
{
	char	**tmp;
	int		i;
	int		z;

	z = 0;
	tmp = ft_split(s->join_args, ' ');
	i = 0;
	while (tmp[i] && tmp[i][0])
	{
		s->a[z++] = ft_atol(tmp[i++], s);
		free(tmp[i - 1]);
	}
	free(tmp);
}

void	init_stacks(int ac, char **av, t_stacks *s)
{
	int	i;

	i = 1;
	s->a_size = 0;
	s->b_size = 0;
	while (--ac)
	{
		if (ft_count_words(av[i], ' '))
			s->a_size += ft_count_words(av[i], ' ');
		else
			s->a_size++;
		i++;
	}
	s->a = malloc(s->a_size * sizeof * s->a);
	if (!(s->a))
		free_exit_message(s, "Error\n");
	s->b = malloc(s->a_size * sizeof * s->b);
	if (!(s->b))
		free_exit_message(s, "Error\n");
}

int	ft_atol(const char *n, t_stacks *s)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] <= ' ')
		i++;
	if ((n[i] == '+' || n[i] == '-'))
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i] && n[i] >= '0' && n[i] <= '9')
	{
		res = res * 10 + (n[i++] - '0');
		if (res > 2147483647)
			free_exit_message (s, "Error\n");
	}
	return ((int)(res * sign));
}

void	exit_if_sorted_or_duplicate(t_stacks *s, int i)
{
	int	j;

	while (i < s->a_size)
	{
		j = i + 1;
		while (j < s->a_size)
		{
			if (s->a[i] == s->a[j])
				free_exit_message(s, "Error\n");
			j++;
		}
		i++;
	}
	if (is_array_sorted(s))
		free_exit_message(s, NULL);
}

void	create_index(t_stacks *s)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	i = -1;
	new_a = malloc(s->a_size * sizeof * new_a);
	if (!new_a)
		free_exit_message(s, "Error\n");
	while (++i < s->a_size)
	{
		k = 0;
		j = -1;
		while (++j < s->a_size)
			if (s->a[i] > s->a[j])
				k++;
		new_a[i] = k;
	}
	i = s->a_size;
	while (i--)
		s->a[i] = new_a[i];
	free(new_a);
}
