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
	int		i;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		prep_clear(&k);
		while ((*format != '%') && (*format))
		{
			k.outn += i++;
			ft_putchar(*format++);
		}
		if (*format == '%' && &(*format++))
			ft_get(ap, &format, &k);
		if (*format)
			format++;
	}
	va_end(ap);
	return (k.outn);
}


int 	main(int argc, char **argv)
{
	int i;

	i = 10;
	/*ft_printf("{d:%hd, i:%li, c:%c, str:%s\t", 3432, -16034343434, 'Z', "bullshit");
	ft_printf("{o:%#o, x:%#x, X:%#X, u:%u}", 34, -245849, 31930002, -160);
	ft_printf("{O:%O,  D:%D, U:%U, p:%p}", 9223372036854775, 9223372036854775807, -9223372036854775807, &i);*/
//	ft_printf("\n-----------Prec--------------------------------------------------\n");
//	ft_printf("x:%.*X\n", 14, 1234324);
//	ft_printf("d:%.33o\n", 12);
//	ft_printf("s:%.1.*s\n", 1, "Bullshit");
//	printf("\n-----------Width--------------------------------------------------\n");
//	ft_printf("d:%*5ld\n", 3, 12);
//	ft_printf("d:%-10*D\n", 5, 12);
//	ft_printf("d:%-10*U\n", 5, 12);
//	ft_printf("c:%30c\n", 'A');
//	ft_printf("s:%.2.*s", 5, "fuck");
//	printf("\tcount: %d\n",  ft_printf("[d:%6d]", -10));
//	ft_printf("[d:%.4d], ", 10);
//	printf("\n-----------Standard--------------------------------------------------\n");
//	printf("{d:%hd, i:%li, c:%c, str:%s\t", 3432, -16034343434, 'Z', "bullshit");
//	printf("{o:%#o, x:%#x, X:%#X, u:%u}", 34, -245849, 31930002, -160);
//	printf("{O:%lo,  D:%ld, U:%lu, p:%p}\n", 9223372036854775, 9223372036854775807, -9223372036854775807, &i);
//	printf("\n-----------Prec--------------------------------------------------\n");
//	printf("x:%.*X\n", 14, 1234324);
//	printf("d:%.33lo\n", 12);
//	printf("s:%.*.1s\n", 40, "Bullshit");
	printf("\n--------------------Width-----------------------------------------\n");
	printf("\tcount: %d\n",  ft_printf("[4d:  [%1d]", 10));
	printf("\tcount: %d\n",  ft_printf("[4d:  [%4d]", -10));
	printf("\tcount: %d\n",  ft_printf("[-4d: [%-4d]", 10));
	printf("\tcount: %d\n",  ft_printf("[-4d: [%-4d]", -10));
	printf("\tcount: %d\n",  ft_printf("[+4d: [%+4d]", 10));
	printf("\tcount: %d\n",  ft_printf("[+4d: [%+4d]", -10));
	printf("\tcount: %d\n",  ft_printf("[-+4d:[%-+4d]", 10));
	printf("\tcount: %d\n",  ft_printf("[-+4d:[%-+4d]", -10));
//	printf("\n-------------------------Prec------------------------------------\n");
//	printf("\tcount: %d\n",  ft_printf("[.4d: [%.4d]", 10));
//	printf("\tcount: %d\n",  ft_printf("[.4d: [%.4d]", -10));
//	printf("\tcount: %d\n",  ft_printf("[+.d: [%+.4d]", 10));
//	printf("\tcount: %d\n",  ft_printf("[+.d: [%+.4d]", -10));
	printf("\n-----------------------Width-------------------------------------\n");
//	printf("d:%*5ld\n", 3, 12);
//	printf("d:%-10*ld\n", 5,  12);
//	printf("d:%-10*lu\n", 5,  12);
//	printf("c:%30c\n", 'A');
//	printf("s:%.2.*s\n", 5, "fuck");
	printf("\tcount: %d\n",  printf("[4d:  [%4d]", 10));
	printf("\tcount: %d\n",  printf("[4d:  [%4d]", -10));
	printf("\tcount: %d\n",  printf("[-4d: [%-4d]", 10));
	printf("\tcount: %d\n",  printf("[-4d: [%-4d]", -10));
	printf("\tcount: %d\n",  printf("[+4d: [%+4d]", 10));
	printf("\tcount: %d\n",  printf("[+4d: [%+4d]", -10));
	printf("\tcount: %d\n",  printf("[-+4d:[%-+4d]", 10));
	printf("\tcount: %d\n",  printf("[-+4d:[%-+4d]", -10));
//	printf("\n--------------------------Prec----------------------------------\n");
//	printf("\tcount: %d\n",  printf("[.4d: [%.4d]", 10));
//	printf("\tcount: %d\n",  printf("[.4d: [%.4d]", -10));
//	printf("\tcount: %d\n",  printf("[+.d: [%+.4d]", 10));
//	printf("\tcount: %d\n",  printf("[+.d: [%+.4d]", -10));

//	printf("[d:%.4d]",-10);
	return (0);
}