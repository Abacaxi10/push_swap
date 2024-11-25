/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabatist <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:40:38 by rabatist          #+#    #+#             */
/*   Updated: 2024/10/15 15:26:36 by rabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_format(va_list va, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_pf(va_arg(va, int));
	else if (c == 's')
		len += ft_putstr_pf(va_arg(va, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_pf(va_arg(va, int));
	else if (c == 'u')
		len += ft_unsigned_putnbr_pf(va_arg(va, unsigned int));
	else if (c == 'x')
		len += ft_putnbr_hex_lower_pf(va_arg(va, unsigned int));
	else if (c == 'X')
		len += ft_putnbr_hex_upper_pf(va_arg(va, unsigned int));
	else if (c == '%')
		len += ft_putchar_pf('%');
	else if (c == 'p')
		len += ft_pointer_pf(va_arg(va, void *));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	va;
	int		len;

	i = 0;
	len = 0;
	va_start(va, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_format(va, str[i]);
		}
		else
			len += ft_putchar_pf(str[i]);
		i++;
	}
	va_end(va);
	return (len);
}
/*
int	main()
{
	ft_printf("%d\n", ft_printf("%x\n", 442347832));
	return (0);
}
*/
