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
**  for %d
*/

void	ft_dec(va_list ap, t_eb *k, const char **format)
{
	k->hash = 0;
	if ((k->h) || (k->hh) || (k->l) || (k->ll) || (k->j) || (k->z))
	{
		(k->h == 1) ? (k->dst = iab((short)(va_arg(ap, int)), 10)) : 0;
		(k->hh == 1) ? (k->dst = iab((signed char)(va_arg(ap, int)), 10)) : 0;
		(k->l == 1) ? (k->dst = iab((va_arg(ap, long)), 10)) : 0;
		(k->ll == 1) ? (k->dst = iab((va_arg(ap, long long)), 10)) : 0;
		(k->j == 1) ? (k->dst = iab((va_arg(ap, intmax_t)), 10)) : 0;
		(k->z == 1) ? (k->dst = iab((va_arg(ap, size_t)), 10)) : 0;
	}
	else
		k->dst = iab((va_arg(ap, int)), 10);
	((k->dst[0] == '0') && (k->p_n == 0) && k->prec) ? (ft_strclr(k->dst)) : 0;
	(k->dst[0] == '-') ? (k->neg = 1) : (k->neg = 0);
	k->prec ? found_preco(k) : 0;
	if ((k->width) && ((k->w_n) > (int)(ft_strlen(k->dst))))
		(((k->plus) || (k->space)) && !(k->neg)) ? found_width(k, format, 1) :
		found_width(k, format, 0);
	else
		print_wany(k, format);
}

/*
**  for %s
*/

void	ft_string(va_list ap, t_eb *k, const char **format)
{
	char *str;

	str = NULL;
	k->plus = 0;
	k->hash = 0;
	k->space = 0;
	k->dst = (va_arg(ap, char *));
	(k->dst == NULL) ? k->dst = "(null)" : 0;
	k->dst != NULL ? (str = ft_strnew((size_t)k->p_n)) : 0;
	if (k->prec && (k->p_n >= 0))
	  ((k->p_n < (int)ft_strlen(k->dst))) ? k->dst = ft_strncpy(str, k->dst, k->p_n) : 0;
	(k->width) ? found_width(k, format, 0) : print_wany(k, format);
	str != NULL ? ft_strdel(&str) : 0;
}

/*
**  for unsigned octal %o
*/

void	ft_ooctal(va_list ap, t_eb *k, const char **format)
{
	k->plus = 0;
	k->space = 0;
	if ((k->h) || (k->hh) || (k->l) || (k->ll) || (k->j) || (k->z))
	{
		(k->h) ? (k->dst = ixb((unsigned short)(va_arg(ap, int)), 8, 0)) : 0;
		(k->hh) ? (k->dst = ixb((unsigned char)(va_arg(ap, int)), 8, 0)) : 0;
		(k->l) ? (k->dst = ixb((va_arg(ap, unsigned long)), 8, 0)) : 0;
		(k->ll) ? (k->dst = ixb((va_arg(ap, unsigned long long)), 8, 0)) : 0;
		(k->j) ? (k->dst = ixb((va_arg(ap, uintmax_t)), 8, 0)) : 0;
		(k->z) ? (k->dst = ixb((va_arg(ap, size_t)), 8, 0)) : 0;
	}
	else
		k->dst = ixb((va_arg(ap, unsigned int)), 8, 0);
	(k->dst[0] == '0' && k->prec && !k->p_n) ? (ft_strclr(k->dst)) : 0;
	k->dst[0] == '0' ? k->hash = 0 : 0;
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
**  for %x and %X
*/

void	ft_xhex(va_list ap, t_eb *k, char const **format)
{
	k->plus = 0;
	k->space = 0;
	**format == 'p' ? k->space = 0 : 0;
	if ((k->h) || (k->hh) || (k->l) || (k->ll) || (k->j) || (k->z))
	{
		(k->h) ? (k->dst = ixb((unsigned short)(va_arg(ap, unsigned int)), 16, format)) : 0;
		(k->hh) ? (k->dst = ixb((unsigned char)(va_arg(ap, unsigned int)), 16, format)) : 0;
		(k->l) ? (k->dst = ixb((va_arg(ap, unsigned long)), 16, format)) : 0;
		(k->ll) ? (k->dst = ixb((va_arg(ap, unsigned long long)), 16, format)) : 0;
		(k->j) ? (k->dst = ixb((va_arg(ap, uintmax_t)), 16, format)) : 0;
		(k->z) ? (k->dst = ixb((va_arg(ap, size_t)), 16, format)) : 0;
	}
	else
		k->dst = ixb((va_arg(ap, unsigned int)), 16, format);
    (k->dst[0] == '0' && **format != 'p') ? (k->hash = 0) : 0;
	if (k->dst[0] == '0')
	{
		k->dst = (char *)malloc(sizeof(char) * 2);
		k->dst[0] = '0';
		k->dst[1] = '\0';
	}
    (k->dst[0] == '0' && k->prec && !k->p_n) ? (ft_strclr(k->dst)) : 0;
	(k->hash && **format != 'p' && **format != 'x') ? (k->p_n -= 2) : 0;
	k->prec ? found_preco(k) : 0;
	k->hash ? (k->w_n -= 2) : 0;
	if ((k->width) && ((k->w_n) > (int)(ft_strlen(k->dst))))
		(((k->plus) || (k->space)) && !(k->neg)) ? found_width(k, format, 1) :
		found_width(k, format, 0);
	else
		print_wany(k, format);
}

/*
**  for unsigned decimal %u
*/

void	ft_udec(va_list ap, t_eb *k, const char **format)
{
	k->plus = 0;
    k->space = 0;
	if ((k->h) || (k->hh) || (k->l) || (k->ll) || (k->j) || (k->z))
	{
		(k->h) ? (k->dst = ixb((unsigned short)(va_arg(ap, unsigned int)), 10, 0)) : 0;
		(k->hh) ? (k->dst = ixb((unsigned char)(va_arg(ap, unsigned int)), 10, 0)) : 0;
		(k->l) ? (k->dst = ixb((va_arg(ap, unsigned long)), 10, 0)) : 0;
		(k->ll) ? (k->dst = ixb((va_arg(ap, unsigned long long)), 10, 0)) : 0;
		(k->j) ? (k->dst = ixb((va_arg(ap, uintmax_t)), 10, 0)) : 0;
		(k->z) ? (k->dst = ixb((va_arg(ap, size_t)), 10, 0)) : 0;
	}
	else
		k->dst = ixb((va_arg(ap, unsigned int)), 10, 0);
    (k->dst[0] == '0' && k->prec && !k->p_n) ? (ft_strclr(k->dst)) : 0;
	k->prec ? found_preco(k) : 0;
	if ((k->width) && ((k->w_n) > (int)(ft_strlen(k->dst))))
		(((k->plus) || (k->space)) && !(k->neg)) ? found_width(k, format, 1) :
		found_width(k, format, 0);
	else
		print_wany(k, format);
}
