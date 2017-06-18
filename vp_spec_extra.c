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

/*
**  for %c
*/

void	ft_char(va_list ap, t_eb *k, const char **format)
{
	k->hash = 0;
	k->space = 0;
	k->plus = 0;
	k->prec = 0;
	k->dst = ft_strnew(1);
	k->dst[0] = (char) va_arg(ap, int);
    if (k->dst[0] == 0)
    {
        k->outn++;
        k->w_n -= 1;
    }
	found_width(k, format, 0);
}

/*
**  for %D
*/

void	ft_lddec(va_list ap, t_eb *k, const char **format)
{
	k->hash = 0;
	if ((k->h) || (k->hh) || (k->l) || (k->ll) || (k->j) || (k->z))
	{
		(k->h == 1) ? (k->l = 1) : 0;
		(k->hh == 1) ? (k->l = 1) : 0;
		(k->l == 1) ? (k->dst = iab((va_arg(ap, long)), 10)) : 0;
		(k->ll == 1) ? (k->dst = iab((va_arg(ap, long long)), 10)) : 0;
		(k->j == 1) ? (k->dst = iab((va_arg(ap, intmax_t)), 10)) : 0;
		(k->z == 1) ? (k->dst = iab((va_arg(ap, size_t)), 10)) : 0;
	}
	else
		k->dst = iab((va_arg(ap, long)), 10);
	((k->dst[0] == '0') && (k->p_n == 0) && k->prec) ? (ft_strclr(k->dst)) : 0;
	(k->dst[0] == '-') ? (k->neg = 1) : (k->neg = 0);
	k->prec ? found_preco(k) : 0;
	if ((k->width) && ((k->w_n) > (int)(ft_strlen(k->dst))))
	{
		(((k->plus) || (k->space)) && !(k->neg)) ? found_width(k, format, 1) :
		found_width(k, format, 0);
	}
	else
		print_wany(k, format);
}

/*
**  for %O
*/

void	ft_looctal(va_list ap, t_eb *k, const char **format)
{
	k->plus = 0;
	k->space = 0;
	if ((k->h) || (k->hh) || (k->l) || (k->ll) || (k->j) || (k->z))
	{
		(k->h) ? (k->l = 1) : 0;
		(k->hh) ? (k->l = 1) : 0;
		(k->l) ? (k->dst = ixb((va_arg(ap, unsigned long)), 8, 0)) : 0;
		(k->ll) ? (k->dst = ixb((va_arg(ap, unsigned long long)), 8, 0)) : 0;
		(k->j) ? (k->dst = ixb((va_arg(ap, uintmax_t)), 8, 0)) : 0;
		(k->z) ? (k->dst = ixb((va_arg(ap, size_t)), 8, 0)) : 0;
	}
	else
		k->dst = ixb((va_arg(ap, unsigned long)), 8, 0);
	(k->dst[0] == '0' && k->prec && !k->p_n) ? (ft_strclr(k->dst)) : 0;
	k->hash ? (k->p_n -= 1) : 0;
	k->prec ? found_preco(k) : 0;
	k->hash ? (k->w_n -= 1) : 0;
	if ((k->width) && ((k->w_n) > (int)(ft_strlen(k->dst))))
	{
		(((k->plus) || (k->space)) && !(k->neg)) ? found_width(k, format, 1) :
		found_width(k, format, 0);
	}
	else
		print_wany(k, format);
}

/*
**  for %U
*/

void	ft_ludec(va_list ap, t_eb *k, const char **format)
{
	k->plus = 0;
	k->space = 0;
	if ((k->h) || (k->hh) || (k->l) || (k->ll) || (k->j) || (k->z))
	{
		(k->h == 1) ? (k->l = 1) : 0;
		(k->hh == 1) ? (k->l = 1) : 0;
		(k->l == 1) ? (k->dst = ixb((va_arg(ap, unsigned long)), 10, 0)) : 0;
		(k->ll == 1) ?
		(k->dst = ixb((va_arg(ap, unsigned long long)), 10, 0)) : 0;
		(k->j == 1) ? (k->dst = ixb((va_arg(ap, uintmax_t)), 10, 0)) : 0;
		(k->z == 1) ? (k->dst = ixb((va_arg(ap, size_t)), 10, 0)) : 0;
	}
	else
		(k->dst == NULL) ? k->dst = ixb((va_arg(ap, unsigned long)), 10, 0) : 0;
	(k->dst[0] == '0' && k->prec && !k->p_n) ? (ft_strclr(k->dst)) : 0;
	k->prec ? found_preco(k) : 0;
	if ((k->width) && ((k->w_n) > (int)(ft_strlen(k->dst))))
		(((k->plus) || (k->space)) && !(k->neg)) ? found_width(k, format, 1) :
		found_width(k, format, 0);
	else
		print_wany(k, format);
}
