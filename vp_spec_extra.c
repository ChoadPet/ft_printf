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


void	ft_char(va_list ap, t_eb *k)
{
	k->dst = ft_strnew(2);
	k->dst[0] = (char)va_arg(ap, int);
	k->dst[1] = '\0';
	write(1, &k->dst[0], 1);
}

/*
**  for %ld or %D
*/

void	ft_lddec(va_list ap, t_eb *k)
{
	(k->h == 1) ? (k->l = 1) : 0;
	(k->hh == 1) ? (k->l = 1) : 0;
	(k->l == 1) ? (k->dst = iab((va_arg(ap, long)), 10)) : 0;
	(k->ll == 1) ? (k->dst = iab((va_arg(ap, long long)), 10)) : 0;
	(k->j == 1) ? (k->dst = iab((va_arg(ap, intmax_t)), 10)) : 0;
	(k->z == 1) ? (k->dst = iab((va_arg(ap, size_t)), 10)) : 0;
	(k->dst == NULL) ? (k->dst = iab((va_arg(ap, long)), 10)) : 0;
	ft_putstr(k->dst);

}

/*
**  for %lo or %O
*/

void	ft_looctal(va_list ap, t_eb *k)
{
	(k->h == 1) ? (k->l = 1) : 0;
	(k->hh == 1) ? (k->l = 1) : 0;
	(k->l == 1) ? (k->dst = ixb((va_arg(ap, unsigned long)), 8, 0)) : 0;
	(k->ll == 1) ? (k->dst = ixb((va_arg(ap, unsigned long long)), 8, 0)) : 0;
	(k->j == 1) ? (k->dst = ixb((va_arg(ap, uintmax_t)), 8, 0)) : 0;
	(k->z == 1) ? (k->dst = ixb((va_arg(ap, size_t)), 8, 0)) : 0;
	(k->dst == NULL) ? (k->dst = ixb((va_arg(ap, unsigned long)), 8, 0)) : 0;
	ft_putstr(k->dst);
}

/*
**  for %lu or %U
*/

void	ft_ludec(va_list ap, t_eb *k)
{
	(k->h == 1) ? (k->l = 1) : 0;
	(k->hh == 1) ? (k->l = 1) : 0;
	(k->l == 1) ? (k->dst = ixb((va_arg(ap, unsigned long)), 10, 0)) : 0;
	(k->ll == 1) ? (k->dst = ixb((va_arg(ap, unsigned long long)), 10, 0)) : 0;
	(k->j == 1) ? (k->dst = ixb((va_arg(ap, uintmax_t)), 10, 0)) : 0;
	(k->z == 1) ? (k->dst = ixb((va_arg(ap, size_t)), 10, 0)) : 0;
	(k->dst == NULL) ? (k->dst = ixb((va_arg(ap, unsigned long)), 10, 0)) : 0;
	ft_putstr(k->dst);
}