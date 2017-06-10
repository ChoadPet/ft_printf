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
	k.outn = 0;
	va_start(ap, format);
	while (*format)
	{
		prep_clear(&k);
		while ((*format != '%') && (*format))
		{
			k.outn++;
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
								// for d AND i

	printf("\tcount: %d\n",  ft_printf("string:  [%s]", 0));
//	printf("\n--------------------Width-----------------------------------------\n");
//	printf("\tcount: %d\n",  ft_printf("[4d:  [%10d]", 0));
//	printf("\tcount: %d\n",  ft_printf("[4d:  [% -014.10d]", 0));
//	printf("\tcount: %d\n",  ft_printf("[-4d: [%d]", 0));
//	printf("\tcount: %d\n",  ft_printf("[d:   [%d]", 0));
//	printf("\tcount: %d\n",  ft_printf("[-+4d:[%6d]", 0));
//	printf("\n-------------------------Prec------------------------------------\n");
//	printf("\tcount: %d\n",  ft_printf("[.4d: [%.4d]", 0));
//	printf("\tcount: %d\n",  ft_printf("[.4d: [%.4d]", 0));
//	printf("\tcount: %d\n",  ft_printf("[+.d: [%+.4d]", 0));
//	printf("\tcount: %d\n",  ft_printf("[+.d: [%+.4d]", 0));
//		printf("\n--------------------Width and Prec-----------------------------------------\n");
//	printf("\tcount: %d\n",  ft_printf("[4d:  [% 06.4.5..0d]", 3));
//	printf("\tcount: %d\n",  ft_printf("[4d:  [% 06.4d]", 0));
//	printf("\tcount: %d\n",  ft_printf("[-4d: [% -06.4d]", 0));
//	printf("\tcount: %d\n",  ft_printf("[-4d: [% -06.4d]", 0));
//	printf("\tcount: %d\n",  ft_printf("[+4d: [%+6.4d]", 0));
//	printf("\tcount: %d\n",  ft_printf("[+4d: [%+6.4d]", 0));
//	printf("\tcount: %d\n",  ft_printf("[-+4d:[%4.d]", 0));
//	printf("\tcount: %d\n",  ft_printf("[-+4d:[% 0d]", 0));



									//STANDARD

	printf("\n++++++++++++++++++++++++++++++++++++++Standard+++++++++++++++++++++\n");

	printf("\tcount: %d\n",  printf("string:  [%20s]", "bull"));
//	printf("\n--------------------Width-----------------------------------------\n");
//	printf("\tcount: %d\n",  printf("[4d:  [%10d]", 0));
//	printf("\tcount: %d\n",  printf("[4d:  [% -014.10d]", 0));
//	printf("\tcount: %d\n",  printf("[-4d: [%d]", 0));
//	printf("\tcount: %d\n",  printf("[d:   [%d]", 0));
//	printf("\tcount: %d\n",  printf("[-+4d:[%6d]", 0));
//	printf("\n-------------------------Prec------------------------------------\n");
//	printf("\tcount: %d\n",  printf("[.4d: [%.4d]", 0));
//	printf("\tcount: %d\n",  printf("[.4d: [%.4d]", 0));
//	printf("\tcount: %d\n",  printf("[+.d: [%+.4d]", 0));
//	printf("\tcount: %d\n",  printf("[+.d: [%+.4d]", 0));
//	printf("\n--------------------Width and Prec-----------------------------------------\n");
//	printf("\tcount: %d\n",  printf("[4d:  [% 06.4.5..0d]", 3));
//	printf("\tcount: %d\n",  printf("[4d:  [% 06.4d]", 0));
//	printf("\tcount: %d\n",  printf("[-4d: [% -06.4d]", 0));
//	printf("\tcount: %d\n",  printf("[-4d: [%- 06.4d]", 0));
//	printf("\tcount: %d\n",  printf("[+4d: [%+6.4d]", 0));
//	printf("\tcount: %d\n",  printf("[+4d: [%+6.4d]", 0));
//	printf("\tcount: %d\n",  printf("[-+4d:[%4.d]", 0));
//	printf("\tcount: %d\n",  printf("[-+4d:[% 0d]", 0));


								// for x AND X


//	printf("{%15p}", 0);



	return (0);
}