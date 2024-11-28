/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:21:20 by rabatist          #+#    #+#             */
/*   Updated: 2024/11/28 15:29:57 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

void	sort_three_elements(t_stacks *s);
int		is_array_sorted(t_stacks *s);
void	sort_four_or_five_elements(t_stacks *s);
void	radix_sort(t_stacks *s);
void	start_sorting(t_stacks *s);

void	free_exit_message(t_stacks *s, char *msg);

void	parse_numbers(t_stacks *s);
void	init_stacks(int ac, char **av, t_stacks *s);
int		ft_atol(const char *n, t_stacks *s);
void	exit_if_sorted_or_duplicate(t_stacks *s, int i);
void	create_index(t_stacks *s);

void	swap(char *str, int *array, int size);
void	rotate(int *array, int size, char *direction, char *list);
void	push(char *direction, t_stacks *s);

#endif