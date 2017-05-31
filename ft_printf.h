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

	int 			minusF;
	int 			plusF;
	int				spaceF;
	int 			hashS;
	int 			zeroS;

	/*
	** 	length modifier
	*/

	int 			h;
	int 			hh;
	int 			l;
	int 			ll;
	int 			j;
	int 			z;

	char 			*sp;
	char 			*fl;

}					t_eb;




/*
** 	 ft_printf. Main function;
*/

int					ft_printf(const char *format, ...);
void				ft_get(va_list ap, const char **format);
void				found_flago(const char **format, t_eb *k);
void				found_speco(const char **format, va_list ap, t_eb *k);

void				ft_dec(va_list ap, t_eb *k);
void				ft_char(va_list ap, t_eb *k);
void				ft_string(va_list ap, t_eb *k);

/*
** main functions for specifiers %d %s and etc
*/



#endif
