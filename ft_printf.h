/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 20:50:34 by vpoltave          #+#    #+#             */
/*   Updated: 2017/03/17 20:53:39 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

/*
** Flags struct:
** 		(-) - A negative field width flag;
** 		(+) - A sign must always be placed before a number produced by a signed conversion.
** 				A + overrides a space if both are used.
**		(0) - Zero padding
** 		(#) - The value should be converted to an ``alternate form''.
** 		(space) - A blank should be left before a positive number produced by
** 			a signed conversion (a, A, d, e, E, f, F, g, G, or i).
 */

typedef struct		s_eb
{
	/*
	** 	flags
	*/

	int 			minus;
	int 			plus;
	int				space;
	int 			hash;
	int 			zero;

	/*
	** Width controls the minimum number
	*/

	int 			width;
	int 			w_n;
	int 			wcount;

	/*
	** Precision controls the max number of characters to print
	*/

	int				prec;
	int 			p_n;
	int 			pcount;

	int 			outn;

	/*
	** 	length modifier
	*/

	int 			h;
	int 			hh;
	int 			l;
	int 			ll;
	int 			j;
	int 			z;
	int 			neg;
	char 			*dst;
	char 			*sp;
	char 			*fl;

}					t_eb;

/*
** 	 ft_printf. Main function;
*/

int					ft_printf(const char *format, ...);
void				ft_get(va_list ap, const char **format, t_eb *k);
void				found_flago(const char **format, t_eb *k);
void				found_speco(const char **format, va_list ap, t_eb *k);

/*
**  vp_extra_function
*/

int					count_dforiab(intmax_t value, int base);
int					count_dforixb(uintmax_t value, int base);
char	 			*iab(intmax_t value, int base);
char				*ixb(uintmax_t value, int base, const char **format);
void				prep_clear(t_eb *k);
int					ft_specdig(int format);

/*
**  functions for width, precision and (-) flag
*/

void				biggest_modifier(t_eb *k, const char **format);
void				fck_preco(va_list ap, const char **format, t_eb *k);
void				fck_width(va_list ap, const char **format, t_eb *k);
void				found_width(t_eb *k, const char **format, int flag);
void				found_preco(t_eb *k);
void				found_ignored(t_eb *k, const char **format);
void				hash_func(t_eb *k, const char **format);

/*
**  print functions
*/

void				print_zero(t_eb *k, const char **format);
void				print_yminus(t_eb *k, const char **format);
void				print_nminus(t_eb *k, const char **format);
void				print_wany(t_eb *k, const char **format);

/*
** main functions for specifiers %d %c and etc
*/

void				ft_dec(va_list ap, t_eb *k, const char **format);
void				ft_string(va_list ap, t_eb *k, const char **format);
void				ft_ooctal(va_list ap, t_eb *k, const char **format);
void				ft_xhex(va_list ap, t_eb *k, const char **format);
void				ft_udec(va_list ap, t_eb *k, const char **format);
void				ft_char(va_list ap, t_eb *k, const char **format);
void				ft_lddec(va_list ap, t_eb *k, const char **format);
void				ft_looctal(va_list ap, t_eb *k, const char **format);
void				ft_ludec(va_list ap, t_eb *k, const char **format);
void				ft_point(va_list ap, t_eb *k, const char **format);

#endif
