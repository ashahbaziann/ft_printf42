/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:18:01 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/02/27 15:54:00 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	n = -n;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

int	d_print(int n)
{
	long	num;

	num = n;
	if (num < 0)
	{
		c_print('-');
		num = -num;
	}
	if (num == 0)
	{
		c_print('0');
		return (1);
	}
	if (num >= 10)
	{
		d_print(num / 10);
		c_print((num % 10) + '0');
	}
	if (num >= 1 && num < 10)
		c_print(num + '0');
	if (n < 0)
		return (num_len(num) + 1);
	else
		return (num_len(num));
}
