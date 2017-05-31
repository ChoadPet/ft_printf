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
	k->dst = iab((va_arg(ap, int)), 10);
	ft_putstr(k->dst);
}

void	ft_string(va_list ap, t_eb *k)
{
	k->dst = (va_arg(ap, char *));
	ft_putstr(k->dst);
}

/*
**  for unsigned octal
*/

void	ft_ooctal(va_list ap, t_eb *k)
{
	k->dst = iab((va_arg(ap, unsigned int)), 8);
	ft_putstr(k->dst);
}

/*
**  for unsigned hexadecimal
*/

void	ft_xhex(va_list ap, t_eb *k, char flag)
{
	k->dst = ixb((va_arg(ap, unsigned int)), 16, flag);
	ft_putstr(k->dst);
}

/*
**  for unsigned decimal
*/

void	ft_udec(va_list ap, t_eb *k)
{
	k->dst = iab((va_arg(ap, unsigned int)), 10);
	ft_putstr(k->dst);
}

