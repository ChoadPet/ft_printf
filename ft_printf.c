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
	int i;

	i = 10;
	/*ft_printf("{d:%hd, i:%li, c:%c, str:%s\t", 3432, -16034343434, 'Z', "bullshit");
	ft_printf("{o:%#o, x:%#x, X:%#X, u:%u}", 34, -245849, 31930002, -160);
	ft_printf("{O:%O,  D:%D, U:%U, p:%p}", 9223372036854775, 9223372036854775807, -9223372036854775807, &i);*/
	ft_printf("\n-----------Prec--------------------------------------------------\n");
	ft_printf("x:%.*X\n", 14, 1234324);
	ft_printf("d:%.33o\n", 12);
	ft_printf("s:%.10*s\n", 7, "Bullshit");
//	printf("\n-----------Width--------------------------------------------------\n");
//	ft_printf("d:%*d\n", 3, 12);
//	ft_printf("d:%10d\n", 12);
//	ft_printf("s:%10s", "fuck");
//	printf("\n-----------Standard--------------------------------------------------\n");
//	printf("{d:%hd, i:%li, c:%c, str:%s\t", 3432, -16034343434, 'Z', "bullshit");
//	printf("{o:%#o, x:%#x, X:%#X, u:%u}", 34, -245849, 31930002, -160);
//	printf("{O:%lo,  D:%ld, U:%lu, p:%p}\n", 9223372036854775, 9223372036854775807, -9223372036854775807, &i);
	printf("\n-----------Prec--------------------------------------------------\n");
	printf("x:%.*X\n", 14, 1234324);
	printf("d:%.33lo\n", 12);
	printf("s:%.7s\n", "Bullshit");
//	printf("\n-----------Width--------------------------------------------------\n");
//	printf("d:%*d\n", 3, 12);
//	printf("d:%10d\n",  12);
//	printf("s:%10s\n", "fuck");
	return (0);
}