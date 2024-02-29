/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:23:53 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/02/26 16:24:32 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	uns_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

int	u_print(unsigned int n)
{
	unsigned long	num;

	num = n;
	if (num == 0)
	{
		c_print('0');
		return (1);
	}
	if (num >= 10)
	{
		u_print(num / 10);
		c_print((num % 10) + '0');
	}
	if (num >= 1 && num < 10)
		c_print(num + '0');
	return (uns_digits(n));
}
