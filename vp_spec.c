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

void	ft_dec(va_list ap, t_eb *k)
{
	(k->h == 1) ? (k->dst = iab((short)(va_arg(ap, int)), 10)) : 0;
	(k->hh == 1) ? (k->dst = iab((signed char)(va_arg(ap, int)), 10)) : 0;
	(k->l == 1) ? (k->dst = iab((va_arg(ap, long)), 10)) : 0;
	(k->ll == 1) ? (k->dst = iab((va_arg(ap, long long)), 10)) : 0;
	(k->j == 1) ? (k->dst = iab((va_arg(ap, intmax_t)), 10)) : 0;
	(k->z == 1) ? (k->dst = iab((va_arg(ap, size_t)), 10)) : 0;
	(k->dst == NULL) ? (k->dst = iab((va_arg(ap, int)), 10)) : 0;
	ft_putstr(k->dst);
}

void	ft_string(va_list ap, t_eb *k)
{
	k->dst = (va_arg(ap, char *));
	ft_putstr(k->dst);
}

/*
**  for unsigned octal %o
*/

void	ft_ooctal(va_list ap, t_eb *k)
{
	(k->h == 1) ? (k->dst = iab((unsigned short)(va_arg(ap, int)), 8)) : 0;
	(k->hh == 1) ? (k->dst = iab((unsigned char)(va_arg(ap, int)), 8)) : 0;
	(k->l == 1) ? (k->dst = iab((va_arg(ap, unsigned long)), 8)) : 0;
	(k->ll == 1) ? (k->dst = iab((va_arg(ap, unsigned long long)), 8)) : 0;
	(k->j == 1) ? (k->dst = iab((va_arg(ap, uintmax_t)), 8)) : 0;
	(k->z == 1) ? (k->dst = iab((va_arg(ap, size_t)), 8)) : 0;
	(k->dst == NULL) ? (k->dst = iab((va_arg(ap, unsigned int)), 8)) : 0;
	ft_putstr(k->dst);
}

/*
**  for %x and %X
*/

void	ft_xhex(va_list ap, t_eb *k, char flag)
{
	(k->h == 1) ? (k->dst = ixb((unsigned short)(va_arg(ap, unsigned int)), 16, flag)) : 0;
	(k->hh == 1) ? (k->dst = ixb((unsigned char)(va_arg(ap, unsigned int)), 16, flag)) : 0;
	(k->l == 1) ? (k->dst = ixb((va_arg(ap, unsigned long)), 16, flag)) : 0;
	(k->ll == 1) ? (k->dst = ixb((va_arg(ap, unsigned long long)), 16, flag)) : 0;
	(k->j == 1) ? (k->dst = ixb((va_arg(ap, uintmax_t)), 16, flag)) : 0;
	(k->z == 1) ? (k->dst = ixb((va_arg(ap, size_t)), 16, flag)) : 0;
	(k->dst == NULL) ? (k->dst = ixb((va_arg(ap, unsigned int)), 16, flag)) : 0;
	ft_putstr(k->dst);
}

/*
**  for unsigned decimal for %u
*/

void	ft_udec(va_list ap, t_eb *k)
{
	(k->h == 1) ? (k->dst = ixb((unsigned short)(va_arg(ap, unsigned int)), 10, 0)) : 0;
	(k->hh == 1) ? (k->dst = ixb((unsigned char)(va_arg(ap, unsigned int)), 10, 0)) : 0;
	(k->l == 1) ? (k->dst = ixb((va_arg(ap, unsigned long)), 10, 0)) : 0;
	(k->ll == 1) ? (k->dst = ixb((va_arg(ap, unsigned long long)), 10, 0)) : 0;
	(k->j == 1) ? (k->dst = ixb((va_arg(ap,  uintmax_t)), 10, 0)) : 0;
	(k->z == 1) ? (k->dst = ixb((va_arg(ap, size_t)), 10, 0)) : 0;
	(k->dst == NULL) ? (k->dst = ixb((va_arg(ap, unsigned long)), 10, 0)) : 0;
	ft_putstr(k->dst);
}

