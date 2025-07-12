/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkaymak < emkaymak@student.42kocaeli.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 22:37:22 by emkaymak          #+#    #+#             */
/*   Updated: 2025/07/12 06:12:44 by emkaymak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_format_handler(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (format == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	if (format == '%')
		return (ft_putchar('%'));
	return (ft_putchar('%') + ft_putchar(format));
}

static int	ft_process_format(va_list args, const char *format, int *i)
{
	int	result;

	if (format[*i] == '%' && format[*i + 1])
		result = ft_format_handler(args, format[++(*i)]);
	else
		result = ft_putchar(format[*i]);
	(*i)++;
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		result;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		result = ft_process_format(args, format, &i);
		if (result == -1)
		{
			va_end(args);
			return (-1);
		}
		count += result;
	}
	va_end(args);
	return (count);
}
