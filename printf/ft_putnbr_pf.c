/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:31:47 by rabatist          #+#    #+#             */
/*   Updated: 2024/10/14 17:45:50 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_pf(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr_pf("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar_pf('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_pf(n / 10);
	count += ft_putchar_pf((n % 10) + '0');
	return (count);
}
/*
#include <stdio.h>

int	main()
{
	int	len;

	len = ft_putnbr_pf(545);
	printf("%d\n", len);
	return (0);
}
*/
