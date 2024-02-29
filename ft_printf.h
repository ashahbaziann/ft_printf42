/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashahbaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:01:17 by ashahbaz          #+#    #+#             */
/*   Updated: 2024/02/27 16:18:23 by ashahbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		c_print(char c);
int		s_print(const char *str);
int		d_print(int n);
int		p_print(unsigned long long p);
int		u_print(unsigned int n);
int		x_print(unsigned int n, char c);

#endif
