/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:19:01 by rabatist          #+#    #+#             */
/*   Updated: 2024/11/28 15:58:16 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit_message(t_stacks *s, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (s != NULL)
	{
		if (s->a)
			free(s->a);
		if (s->b)
			free(s->b);
		if (s->join_args)
			free(s->join_args);
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
	char	*result;
	char	*tmp;
	int		i;

	i = 1;
	result = ft_strdup("");
	if (!result)
		free_exit_message(s, "Error\n");
	while (i < ac)
	{
		tmp = result;
		result = ft_strjoin(result, av[i]);
		if (!result)
			free_exit_message(s, "Error\n");
		free(tmp);
		if (i++ < ac - 1)
		{
			tmp = result;
			result = ft_strjoin(result, " ");
			if (!result)
				free_exit_message(s, "Error\n");
			free(tmp);
		}
	}
	s->join_args = result;
}

void	start_sorting(t_stacks *s)
{
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	else if (s->a_size == 3)
		sort_three_elements(s);
	else if (s->a_size == 4 || s->a_size == 5)
		sort_four_or_five_elements(s);
	else
		radix_sort(s);
}

int	main(int ac, char **av)
{
	t_stacks	*s;

	valide_arguments(ac, av);
	s = malloc(sizeof * s);
	if (!s)
		free_exit_message(s, "Error\n");
	init_stacks(ac, av, s);
	join_args(ac, av, s);
	parse_numbers(s);
	exit_if_sorted_or_duplicate(s, 0);
	create_index(s);
	start_sorting(s);
	exit_if_sorted_or_duplicate(s, 1);
	free_exit_message(s, "Error\n");
	return (0);
}
