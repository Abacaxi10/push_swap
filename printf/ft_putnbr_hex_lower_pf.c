/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_lower_pf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:10:25 by rabatist          #+#    #+#             */
/*   Updated: 2024/10/15 16:30:07 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_hex_lower_pf(unsigned int n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n == 0)
	{
		count += ft_putchar_pf('0');
		return (count);
	}
	if (n >= 16)
		count += ft_putnbr_hex_lower_pf(n / 16);
	count += ft_putchar_pf(hex[n % 16]);
	return (count);
}
/*
#include <stdio.h>

int	main()
{
	unsigned int a;

	a = 4523432;
	printf("%x\n", ft_putnbr_hex_lower_pf(a));
	return (0);
}
*/
