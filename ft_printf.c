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
	t_eb	k;

	va_start(ap, format);
	while (*format)
	{
		while (*format != '%' && *format)
			ft_putchar(*format++);
		if (*format == '%' && &(*format++))
		{
			prep_clear(&k);
			ft_get(ap, &format, &k);
		}
		if (*format)
			format++;
	}
	va_end(ap);
	return (1);
}


int 	main(int argc, char **argv)
{
	ft_printf("{d:%hd, i:%li, c:%c, str:%s\t", 3432, -16034343434, 'Z', "bullshit");
	ft_printf("{o:%hho, x:%hx, X:%X, u:%hhu}", 34, -245849, 31930002, -160);
	ft_printf("{O:%O,  D:%D, U:%U}", 9223372036854775, 9223372036854775807, -9223372036854775807);
	printf("\n-----------Standard--------------------------------------------------\n");
	printf("{d:%hd, i:%li, c:%c, str:%s\t", 3432, -16034343434, 'Z', "bullshit");
	printf("{o:%hho, x:%hx, X:%X, u:%hhu}", 34, -245849, 31930002, -160);
	printf("{O:%lo,  D:%ld, U:%lu}", 9223372036854775, 9223372036854775807, -9223372036854775807);
	printf("\n-----------Standard--------------------------------------------------\n");
	return (0);
}