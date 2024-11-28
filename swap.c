/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <rabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:41:52 by rabatist          #+#    #+#             */
/*   Updated: 2024/11/28 14:23:07 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *str, int *array, int size)
{
	int	tmp;

	if (size > 1)
	{
		tmp = array[0];
		array[0] = array[1];
		array[1] = tmp;
		ft_printf("%s\n", str);
	}
}
