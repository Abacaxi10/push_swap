/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:21:13 by rabatist          #+#    #+#             */
/*   Updated: 2024/10/14 17:07:13 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr_pf(char *str)
{
	int	count;
	int	i;

	if (!str)
		return (ft_putstr_pf("(null)"));
	count = 0;
	i = 0;
	while (str[i])
	{
		count += ft_putchar_pf(str[i]);
		i++;
	}
	return (count);
}
