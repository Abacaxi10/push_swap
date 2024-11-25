/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_upper_pf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:27:27 by rabatist          #+#    #+#             */
/*   Updated: 2024/10/15 13:34:10 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_hex_upper_pf(unsigned int n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n == 0)
	{
		count += ft_putchar_pf('0');
		return (count);
	}
	if (n >= 16)
		count += ft_putnbr_hex_upper_pf(n / 16);
	count += ft_putchar_pf(hex[n % 16]);
	return (count);
}
