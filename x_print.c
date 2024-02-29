/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:56:45 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/02/27 15:55:47 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	x_digits(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		count++;
		num = num / 16;
	}
	return (count);
}

int	x_print(unsigned int num, char c)
{
	if (num >= 16)
	{
		x_print(num / 16, c);
		x_print(num % 16, c);
	}
	else
	{
		if (num >= 10 && num <= 15)
		{
			if (c == 'x')
				c_print((num - 10) + 97);
			else
				c_print((num - 10) + 65);
		}
		else
			c_print(num + '0');
	}
	return (x_digits(num));
}
