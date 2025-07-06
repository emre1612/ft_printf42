/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkaymak <emkaymak@student.42.kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 23:10:34 by emkaymak          #+#    #+#             */
/*   Updated: 2025/07/06 15:35:51 by emkaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunbr(n / 10);
		count += ft_putunbr(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_puthex(unsigned int n, char format)
{
	int		count;
	char	*base;

	count = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_puthex(n / 16, format);
		count += ft_puthex(n % 16, format);
	}
	else
		count += ft_putchar(base[n]);
	return (count);
}

int	ft_putptr(unsigned long ptr)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	if (ptr >= 16)
		count += ft_putptr(ptr / 16);
	else
		count += ft_putstr("0x");
	count += ft_putchar(hex[ptr % 16]);
	return (count);
}
