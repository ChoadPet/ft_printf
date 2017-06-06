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

void	ft_dec(va_list ap, t_eb *k)
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
	if (k->prec)
	{
		found_preco(k);
		((k->plus) && !(k->neg)) ? k->dst = ft_strjoin("+", k->dst) : 0;
	}
	if (k->width)
		found_width(k);
	ft_putstr(k->dst);
}

/*
**  for %s
*/

void	ft_string(va_list ap, t_eb *k)
{
	int count;

	k->dst = (va_arg(ap, char *));
	if ((k->prec) && !(k->width))
	{
		if (k->p_n <= ft_strlen(k->dst))
			write(1, k->dst, (size_t)k->p_n);
		else
			ft_putstr(k->dst);
	}
	else if ((k->width) && !(k->prec))
	{
		if (k->w_n > ft_strlen(k->dst))
		{
			count = (k->w_n - (int)ft_strlen(k->dst));
			while (count--)
				write(1, " ", 1);
		}
		ft_putstr(k->dst);
	}
	else
		ft_putstr(k->dst);
}

/*
**  for unsigned octal %o
*/

void	ft_ooctal(va_list ap, t_eb *k)
{
	k->plus = 0;
	(k->hash == 1) ? ft_putstr("0") : 0;
	if ((k->h) || (k->hh) || (k->l) || (k->ll) || (k->j) || (k->z))
	{
		(k->h == 1) ? (k->dst = iab((unsigned short)(va_arg(ap, int)), 8)) : 0;
		(k->hh == 1) ? (k->dst = iab((unsigned char)(va_arg(ap, int)), 8)) : 0;
		(k->l == 1) ? (k->dst = iab((va_arg(ap, unsigned long)), 8)) : 0;
		(k->ll == 1) ? (k->dst = iab((va_arg(ap, unsigned long long)), 8)) : 0;
		(k->j == 1) ? (k->dst = iab((va_arg(ap, uintmax_t)), 8)) : 0;
		(k->z == 1) ? (k->dst = iab((va_arg(ap, size_t)), 8)) : 0;
	}
	else
		k->dst = iab((va_arg(ap, unsigned int)), 8);
	ft_putstr(k->dst);
}

/*
**  for %x and %X
*/

void	ft_xhex(va_list ap, t_eb *k, char flag)
{
	k->plus = 0;
	((k->hash == 1) && (flag == 'l')) ? ft_putstr("0x") : 0;
	((k->hash == 1) && (flag == 'u')) ? ft_putstr("0X") : 0;
	if ((k->h) || (k->hh) || (k->l) || (k->ll) || (k->j) || (k->z))
	{
		(k->h == 1) ? (k->dst = ixb((unsigned short)(va_arg(ap, unsigned int)), 16, flag)) : 0;
		(k->hh == 1) ? (k->dst = ixb((unsigned char)(va_arg(ap, unsigned int)), 16, flag)) : 0;
		(k->l == 1) ? (k->dst = ixb((va_arg(ap, unsigned long)), 16, flag)) : 0;
		(k->ll == 1) ? (k->dst = ixb((va_arg(ap, unsigned long long)), 16, flag)) : 0;
		(k->j == 1) ? (k->dst = ixb((va_arg(ap, uintmax_t)), 16, flag)) : 0;
		(k->z == 1) ? (k->dst = ixb((va_arg(ap, size_t)), 16, flag)) : 0;
	}
	else
		k->dst = ixb((va_arg(ap, unsigned int)), 16, flag);
	ft_putstr(k->dst);
}

/*
**  for unsigned decimal %u
*/

void	ft_udec(va_list ap, t_eb *k)
{
	k->plus = 0;
	if ((k->h) || (k->hh) || (k->l) || (k->ll) || (k->j) || (k->z))
	{
		(k->h == 1) ? (k->dst = ixb((unsigned short) (va_arg(ap, unsigned int)), 10, 0)) : 0;
		(k->hh == 1) ? (k->dst = ixb((unsigned char) (va_arg(ap, unsigned int)), 10, 0)) : 0;
		(k->l == 1) ? (k->dst = ixb((va_arg(ap, unsigned long)), 10, 0)) : 0;
		(k->ll == 1) ? (k->dst = ixb((va_arg(ap, unsigned long long)), 10, 0)) : 0;
		(k->j == 1) ? (k->dst = ixb((va_arg(ap, uintmax_t)), 10, 0)) : 0;
		(k->z == 1) ? (k->dst = ixb((va_arg(ap, size_t)), 10, 0)) : 0;
	}
	else
		k->dst = ixb((va_arg(ap, unsigned long)), 10, 0);
	ft_putstr(k->dst);
}

