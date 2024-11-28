/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:55:50 by rabatist          #+#    #+#             */
/*   Updated: 2024/11/28 14:22:46 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_up(int *array, int size)
{
	int	tmp;
	int	i;

	tmp = array[0];
	i = 0;
	while (i < size - 1)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[size - 1] = tmp;
}

static void	rotate_down(int *array, int size)
{
	int	tmp;
	int	i;

	tmp = array[size - 1];
	i = size - 1;
	while (i > 0)
	{
		array[i] = array[i - 1];
		i--;
	}
	array[0] = tmp;
}

void	rotate(int *array, int size, char *direction, char *list)
{
	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 2) == 0)
	{
		rotate_up(array, size);
		ft_printf("r");
	}
	else if (ft_strncmp(direction, "down", 4) == 0)
	{
		rotate_down(array, size);
		ft_printf("rr");
	}
	ft_printf("%s\n", list);
}
