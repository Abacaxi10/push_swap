/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_pf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:59:46 by rabatist          #+#    #+#             */
/*   Updated: 2024/10/14 16:59:19 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_unsigned_putnbr_pf(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_unsigned_putnbr_pf(n / 10);
	count += ft_putchar_pf((n % 10) + '0');
	return (count);
}
