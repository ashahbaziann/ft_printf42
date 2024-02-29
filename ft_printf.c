/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:41:37 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/02/27 16:16:53 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	check_form(char form, va_list args)
{
	int	length;

	length = 0;
	if (form == 'c')
		length += c_print(va_arg(args, int));
	else if (form == 's')
		length += s_print(va_arg(args, const char *));
	else if (form == 'd' || form == 'i')
		length += d_print(va_arg(args, int));
	else if (form == 'p')
	{
		length += write (1, "0x", 2);
		length += p_print(va_arg(args, unsigned long long));
	}
	else if (form == 'u')
		length += u_print(va_arg(args, unsigned int));
	else if (form == 'x')
		length += x_print(va_arg(args, unsigned int), form);
	else if (form == 'X')
		length += x_print(va_arg(args, unsigned int), form);
	else if (form == '%')
		length += c_print(form);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			length += check_form(format[i], args);
		}
		else
		{
			length++;
			write (1, &format[i], 1);
		}
		i++;
	}
	return (length);
}
