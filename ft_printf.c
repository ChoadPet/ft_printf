/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:45:14 by vpoltave          #+#    #+#             */
/*   Updated: 2017/03/17 20:50:22 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		while (*format != '%' && *format)
			ft_putchar(*format++);
		if (*format == '%' && &(*format++))
			ft_get(ap, &format);
		format++;
	}
	va_end(ap);
	return (1);
}


int 	main(int argc, char **argv)
{
	int 	i;
	int 	j;
	char 	c;
	char 	*str;

	j = 230;
	i = 16;
	c = 'A';
	str = "pick";
	ft_printf("{i:%d, j:%i, c:%c, str:%s}", i, j, c, str);
	printf("\n-----------------------------------------\n");
	printf("{printf: i:%d j:%i c:%c str:%s}", i, j, c, str);
	return (0);
}