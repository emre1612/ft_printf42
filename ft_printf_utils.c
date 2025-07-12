/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkaymak < emkaymak@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:25:19 by emkaymak          #+#    #+#             */
/*   Updated: 2025/07/12 04:38:46 by emkaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	result;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i])
	{
		result = ft_putchar(str[i]);
		if (result == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	len;
	int	tmp;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
		n *= -1;
	}
	if (n > 9)
	{
		tmp = ft_putnbr(n / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (ft_putchar("0123456789"[n % 10]) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putunbr(unsigned int n)
{
	int	count;
	int	result;

	count = 0;
	if (n >= 10)
	{
		result = ft_putunbr(n / 10);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar((n % 10) + '0');
	if (result == -1)
		return (-1);
	count += result;
	return (count);
}

int	ft_puthex(unsigned int n, char format)
{
	int		count;
	char	*base;
	int		result;

	count = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		result = ft_puthex(n / 16, format);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar(base[n % 16]);
	if (result == -1)
		return (-1);
	count += result;
	return (count);
}

int	ft_putptr(unsigned long ptr)
{
	int		count;
	int		result;

	count = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	if (ptr >= 16)
	{
		result = ft_putptr(ptr / 16);
		if (result == -1)
			return (-1);
		count += result;
	}
	else
	{
		result = ft_putstr("0x");
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar("0123456789abcdef"[ptr % 16]);
	if (result == -1)
		return (-1);
	count += result;
	return (count);
}
