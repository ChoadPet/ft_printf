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
								// for %d AND %i

/*	printf("\n--------------------Width-----------------------------------------\n");
	printf("\tcount: %d\n",  ft_printf("[4d:  [%10d]", 0));
	printf("\tcount: %d\n",  ft_printf("[4d:  [% -014.10d]", 0));
	printf("\tcount: %d\n",  ft_printf("[-4d: [%d]", 0));
	printf("\tcount: %d\n",  ft_printf("[d:   [%d]", 0));
	printf("\tcount: %d\n",  ft_printf("[-+4d:[%6d]", 0));
	printf("\n-------------------------Prec------------------------------------\n");
	printf("\tcount: %d\n",  ft_printf("[.4d: [%.4d]", 0));
	printf("\tcount: %d\n",  ft_printf("[.4d: [%.4d]", 0));
	printf("\tcount: %d\n",  ft_printf("[+.d: [%+.4d]", 0));
	printf("\tcount: %d\n",  ft_printf("[+.d: [%+.4d]", 0));
		printf("\n--------------------Width and Prec-----------------------------------------\n");
	printf("\tcount: %d\n",  ft_printf("[4d:  [% 06.4.5..0d]", 3));
	printf("\tcount: %d\n",  ft_printf("[4d:  [% 06.4d]", 0));
	printf("\tcount: %d\n",  ft_printf("[-4d: [% -06.4d]", 0));
	printf("\tcount: %d\n",  ft_printf("[-4d: [% -06.4d]", 0));
	printf("\tcount: %d\n",  ft_printf("[+4d: [%+6.4d]", 0));
	printf("\tcount: %d\n",  ft_printf("[+4d: [%+6.4d]", 0));
	printf("\tcount: %d\n",  ft_printf("[-+4d:[%4.d]", 0));
	printf("\tcount: %d\n",  ft_printf("[-+4d:[% 0d]", 0));*/

						// for %o AND %O

//	printf("\n--------------------Width-----------------------------------------\n");
//	printf("\tcount: %d\n",  ft_printf("[4d:  [%#10o]", 10));
//	printf("\tcount: %d\n",  ft_printf("[4d:  [% #-014.10o]", 10));
//	printf("\tcount: %d\n",  ft_printf("[-4d: [%#1o]", 10));
//	printf("\tcount: %d\n",  ft_printf("[d:   [%#o]", 10));
//	printf("\tcount: %d\n",  ft_printf("[-+4d:[%#6o]", 10));
//	printf("\n-------------------------Prec------------------------------------\n");
//	printf("\tcount: %d\n",  ft_printf("[.4d: [%#.4o]", -10));
//	printf("\tcount: %d\n",  ft_printf("[.4d: [%#.4o]", 10));
//	printf("\tcount: %d\n",  ft_printf("[+.d: [%#+.4o]", -10));
//	printf("\tcount: %d\n",  ft_printf("[+.d: [%#+.4o]", 10));
//	printf("\n--------------------Width and Prec-----------------------------------------\n");
//	printf("\tcount: %d\n",  ft_printf("[4d:  [% #06.4.5..0o]", 3));
//	printf("\tcount: %d\n",  ft_printf("[4d:  [% #06.4o]", 10));
//	printf("\tcount: %d\n",  ft_printf("[-4d: [% #-06.4o]", 10));
//	printf("\tcount: %d\n",  ft_printf("[-4d: [% #-06.4o]", 10));
//	printf("\tcount: %d\n",  ft_printf("[+4d: [%+#6.4o]", 10));
//	printf("\tcount: %d\n",  ft_printf("[+4d: [%+#6.4o]", 10));
//	printf("\tcount: %d\n",  ft_printf("[-+4d:[%4#.o]", 10));
//	printf("\tcount: %d\n",  ft_printf("[-+4d:[% 0o]", 10));

									//STANDARD

	printf("\n++++++++++++++++++++++++++++++++++++++Standard+++++++++++++++++++++\n");

									// for %d AND %i

/*	printf("\n--------------------Width-----------------------------------------\n");
	printf("\tcount: %d\n",  printf("[4d:  [%10d]", 0));
	printf("\tcount: %d\n",  printf("[4d:  [% -014.10d]", 0));
	printf("\tcount: %d\n",  printf("[-4d: [%d]", 0));
	printf("\tcount: %d\n",  printf("[d:   [%d]", 0));
	printf("\tcount: %d\n",  printf("[-+4d:[%6d]", 0));
	printf("\n-------------------------Prec------------------------------------\n");
	printf("\tcount: %d\n",  printf("[.4d: [%.4d]", 0));
	printf("\tcount: %d\n",  printf("[.4d: [%.4d]", 0));
	printf("\tcount: %d\n",  printf("[+.d: [%+.4d]", 0));
	printf("\tcount: %d\n",  printf("[+.d: [%+.4d]", 0));
	printf("\n--------------------Width and Prec-----------------------------------------\n");
	printf("\tcount: %d\n",  printf("[4d:  [% 06.4.5..0d]", 3));
	printf("\tcount: %d\n",  printf("[4d:  [% 06.4d]", 0));
	printf("\tcount: %d\n",  printf("[-4d: [% -06.4d]", 0));
	printf("\tcount: %d\n",  printf("[-4d: [%- 06.4d]", 0));
	printf("\tcount: %d\n",  printf("[+4d: [%+6.4d]", 0));
	printf("\tcount: %d\n",  printf("[+4d: [%+6.4d]", 0));
	printf("\tcount: %d\n",  printf("[-+4d:[%4.d]", 0));
	printf("\tcount: %d\n",  printf("[-+4d:[% 0d]", 0));*/

					// for %o AND %O

//	printf("\n--------------------Width-----------------------------------------\n");
//	printf("\tcount: %d\n",  printf("[4d:  [%#10o]", 10));
//	printf("\tcount: %d\n",  printf("[4d:  [%# -014.10o]", 10));
//	printf("\tcount: %d\n",  printf("[-4d: [%#1o]", 10));
//	printf("\tcount: %d\n",  printf("[d:   [%#o]", 10));
//	printf("\tcount: %d\n",  printf("[-+4d:[%#6o]", 10));
//	printf("\n-------------------------Prec------------------------------------\n");
//	printf("\tcount: %d\n",  printf("[.4d: [%#.4o]", -10));
//	printf("\tcount: %d\n",  printf("[.4d: [%#.4o]", 10));
//	printf("\tcount: %d\n",  printf("[+.d: [%#+.4o]", -10));
//	printf("\tcount: %d\n",  printf("[+.d: [%#+.4o]", 10));
//	printf("\n--------------------Width and Prec-----------------------------------------\n");
//	printf("\tcount: %d\n",  printf("[4d:  [% #06.4.5..0o]", 3));
//	printf("\tcount: %d\n",  printf("[4d:  [% #06.4o]", 10));
//	printf("\tcount: %d\n",  printf("[-4d: [% #-06.4o]", 10));
//	printf("\tcount: %d\n",  printf("[-4d: [% #-06.4o]", 10));
//	printf("\tcount: %d\n",  printf("[+4d: [%+#6.4o]", 10));
//	printf("\tcount: %d\n",  printf("[+4d: [%+#6.4o]", 10));
//	printf("\tcount: %d\n",  printf("[-+4d:[%#4.o]", 10));
//	printf("\tcount: %d\n",  printf("[-+4d:[% 0o]", 10));

								// for x AND X

	return (0);
}