/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:56:54 by rabatist          #+#    #+#             */
/*   Updated: 2024/10/15 15:14:27 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_put_pointer_pf(uintptr_t ptr)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (ptr >= 16)
		count += ft_put_pointer_pf(ptr / 16);
	count += ft_putchar_pf(hex[ptr % 16]);
	return (count);
}

int	ft_pointer_pf(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		count += ft_putstr_pf("0x0");
	else
	{
		count += ft_putstr_pf("0x");
		count += ft_put_pointer_pf((uintptr_t)ptr);
	}
	return (count);
}
