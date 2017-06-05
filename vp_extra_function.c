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
** count digits for regular itoa_base
*/

int		count_dforiab(intmax_t value, int base)
{
	int i;

	i = 0;
	if ((value <= 0) && (base == 10))
		i++;
	while (value != 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

/*
** count digits for (%O, %x %X etc) itoa_base
*/

int		count_dforixb(uintmax_t value, int base)
{
	int i;

	i = 0;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

/*
** regular itoa_base
*/

char	*iab(intmax_t value, int base)
{
	intmax_t	i;
	int			j;
	char		*str;

	j = count_dforiab(value, base);
	str = (char *)malloc(sizeof(char) * (j + 1));
	str[j] = '\0';
	if (value == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	while (value)
	{
		i = value % base;
		if (value < 0)
			i = -i;
		if (i > 9)
			i += 7;
		str[j-- - 1] = (char)(i + 48);
		value /= base;
	}
	return (str);
}

/*
** (%O, %x %X etc) itoa_base
*/

char	*ixb(uintmax_t value, int base, char flag)
{
	uintmax_t	i;
	int			j;
	char		*str;

	j = count_dforixb(value, base);
	str = (char *)malloc(sizeof(char) * (j + 1));
	str[j] = '\0';
	if (value == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (value)
	{
		i = value % base;
		if ((i > 9) && (flag == 'u'))
			i += 7;
		else if ((i > 9) && (flag == 'l'))
			i += 39;
		str[j-- - 1] = (char)(i + 48);
		value /= base;
	}
	return (str);
}

/*
** function that clear all flags and other shit
*/

void	prep_clear(t_eb *k)
{
	k->minus = 0;
	k->plus = 0;
	k->space = 0;
	k->hash = 0;
	k->zero = 0;
	k->h = 0;
	k->hh = 0;
	k->l = 0;
	k->ll = 0;
	k->j = 0;
	k->z = 0;
	k->w_n = 0;
	k->p_n = 0;
	k->width = 0;
	k->prec = 0;
	k->outn = 0;
	k->neg = 0;
	k->dst = NULL;
}
