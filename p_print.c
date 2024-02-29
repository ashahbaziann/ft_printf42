/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:00:58 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/02/27 16:19:09 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_count(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (1);
	while (ptr)
	{
		count++;
		ptr = ptr / 16;
	}
	return (count);
}

int	p_print(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		p_print(ptr / 16);
		p_print(ptr % 16);
	}
	else
	{
		if (ptr > 9)
			c_print((ptr - 10) + 'a');
		else
			c_print(ptr + '0');
	}
	return (p_count(ptr));
}
