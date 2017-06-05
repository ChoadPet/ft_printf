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

void	ft_get(va_list ap, const char **format, t_eb *k)
{
	k->sp = "sSpdDioOuUxXcC";
	k->fl = "#0-+#.*123456789 hljz";
	while (ft_strchr(k->fl, **format))
	{
		if (ft_specdig(**format) || **format == '*')
			fck_width(ap, format, k);
		if (**format == '.')
			fck_preco(ap, format, k);
		found_flago(format, k);
		biggest_modifier(k);
		((ft_strchr(k->fl, **format))) ? (*format)++ : 0;
	}
	if (ft_strchr(k->sp, **format))
		found_speco(format, ap, k);
}

void	found_flago(const char **format, t_eb *k)
{
	(**format == '-') ? (k->minus = 1) : 0;
	(**format == '+') ? (k->plus = 1) : 0;
	(**format == ' ') ? (k->space = 1) : 0;
	(**format == '#') ? (k->hash = 1) : 0;
	(**format == '0') ? (k->zero = 1) : 0;
	if ((**format == 'h') && (*(*format + 1) == 'h'))
	{
		k->hh = 1;
		(*format)++;
	}
	else if (**format == 'h')
		k->h = 1;
	if ((**format == 'l') && (*(*format + 1) == 'l'))
	{
		k->ll = 1;
		(*format)++;
	}
	else if (**format == 'l')
		k->l = 1;
	if (**format == 'j')
		k->j = 1;
	if (**format == 'z')
		k->z = 1;
}

void	found_speco(const char **format, va_list ap, t_eb *k)
{
	((**format == 'd') || (**format == 'i')) ? ft_dec(ap, k) : 0;
	(**format == 's') ? ft_string(ap, k) : 0;
	(**format == 'o') ? ft_ooctal(ap, k) : 0;
	(**format == 'O') ? ft_looctal(ap, k) : 0;
	(**format == 'x') ? ft_xhex(ap, k, 'l') : 0;
	(**format == 'X') ? ft_xhex(ap, k, 'u') : 0;
	(**format == 'u') ? ft_udec(ap, k) : 0;
	(**format == 'U') ? ft_ludec(ap, k): 0;
	((**format == 'c') || (**format == 'C')) ? ft_char(ap, k) : 0;
	(**format == 'D') ? ft_lddec(ap, k) : 0;
	(**format == 'p') ? ft_point(ap, k) : 0;

}

