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
	ft_printf("{d:%d, i:%i, D:%D, c:%c, str:%s\t", -3432, 160, -235484834483, 'Z', "bullshit");
	ft_printf("{o:%o, O:%O, x:%x, X:%X, u:%u, U:%U}", -3432, -234343433232, 160, 160, 23541, 234343433232);
	printf("\n-----------Standard--------------------------------------------------\n");
	printf("{d:%d, i:%i, D:%ld, c:%c, str:%s\t", -3432, 160, -235484834483, 'Z', "bullshit");
	printf("{o:%o, O:%lo, x:%x, X:%X, u:%u, U:%lu}", -3432, -234343433232, 160, 160, 23541, 234343433232);
	printf("\n-----------Standard--------------------------------------------------\n");
	return (0);
}