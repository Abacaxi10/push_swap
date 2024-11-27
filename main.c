/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:19:01 by rabatist          #+#    #+#             */
/*   Updated: 2024/11/27 19:23:04 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit_message(t_stacks *s, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (s != NULL)
	{
		if (!(s->a))
			free(s->a);
		if (!(s->b))
			free(s->b);
		if (!(s->join_args))
			free(s->join_args);
		if (!s)
			free (s);
	}
	exit(1);
}

static void	valide_arguments(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	if (ac < 2)
		free_exit_message(NULL, "Error\n");
	while (++i < ac)
	{
		j = 0;
		if (!av[i][0] || (av[i][0] && av[i][0] == ' '))
			free_exit_message(NULL, "Error\n");
		while (av[i][j])
		{
			if ((!(ft_isdigit(av[i][j])) && (av[i][j] != ' ')
			&& (av[i][j] != '-')) || (av[i][j] == '-' && av[i][j + 1] == '\0')
			|| (av[i][j] == '-' && av[i][j + 1] == ' '))
				free_exit_message(NULL, "Error\n");
			j++;
		}
	}
}

static void	join_args(int ac, char **av, t_stacks *s)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < ac && av[i])
	{
		tmp = ft_strjoin(tmp2, av[i]);
		if (tmp2)
			free(tmp2);
		if (i != ac - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	s->join_args = ft_strdup(tmp);
	if (!(s->join_args))
		free_exit_message(s, "Error\n");
	if (tmp)
		free (tmp);
}

int	main(int ac, char **av)
{
	t_stacks	*s;

	valide_arguments(ac, av);
	s = malloc(sizeof * s);
	if (!s)
		exit(1);
	init_stacks(ac, av, s);
	join_args(ac, av, s);
	parse_numbers(s);
	exit_if_sorted_or_duplicate(s, 0);
	create_index(s);
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	else if (s->a_size == 3)
		sort_three_elements(s);
	else if (s->a_size == 4 || s->a_size == 5)
		sort_four_or_five_elements(s);
	else
		radix_sort(s);
	exit_if_sorted_or_duplicate(s, 1);
	free_exit_message(s, "Error\n");
	return (0);
}
