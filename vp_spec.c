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
	int d;

	d = va_arg(ap, int);
	ft_putnbr(d);
}

void	ft_char(va_list ap, t_eb *k)
{
	char c;

	c = va_arg(ap, int);
	write(1, &c, 1);
}

void	ft_string(va_list ap, t_eb *k)
{
	char *str;

	str = va_arg(ap, char *);
	ft_putstr(str);
}

char 	*ft_ib(int nubmer, int base)
{
	int i;
	int j;


}