/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:36:09 by rabatist          #+#    #+#             */
/*   Updated: 2024/11/28 14:22:19 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_pb(t_stacks *s)
{
	int	tmp;
	int	i;

	if (s->a_size <= 0)
		return ;
	tmp = s->a[0];
	i = s->b_size;
	while (i > 0)
	{
		s->b[i] = s->b[i - 1];
		i--;
	}
	s->b[0] = tmp;
	s->b_size++;
	s->a_size--;
	i = 0;
	while (i < s->a_size)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
}

static void	push_pa(t_stacks *s)
{
	int	tmp;
	int	i;

	if (s->b_size <= 0)
		return ;
	tmp = s->b[0];
	i = s->a_size;
	while (i > 0)
	{
		s->a[i] = s->a[i - 1];
		i--;
	}
	s->a[0] = tmp;
	s->a_size++;
	s->b_size--;
	i = 0;
	while (i < s->b_size)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
}

void	push(char *direction, t_stacks *s)
{
	if (ft_strncmp(direction, "pa", 2) == 0)
		push_pa(s);
	else if (ft_strncmp(direction, "pb", 2) == 0)
		push_pb(s);
	ft_printf("%s\n", direction);
}
