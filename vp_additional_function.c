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

void	biggest_modifier(t_eb *k, const char **format)
{
	if (k->z == 1)
	{
		k->h = 0;
		k->hh = 0;
		k->l = 0;
		k->ll = 0;
		k->j = 0;
	}
	else if (k->j == 1)
	{
		k->h = 0;
		k->hh = 0;
		k->l = 0;
		k->ll = 0;
	}
	else if (k->ll == 1)
	{
		k->h = 0;
		k->hh = 0;
		k->l = 0;
	}
	if ((k->l == 1) && !(k->h = 0))
		k->hh = 0;
	k->h == 1 ? k->hh = 0 : 0;
	found_ignored(k, format);
}

int		ft_specdig(int format)
{
	if (format >= '1' && format <= '9')
		return (1);
	else
		return (0);
}

void	fck_width(va_list ap, const char **format, t_eb *k)
{
	k->width = 1;
	while (ft_isdigit(**format) || **format == '*')
	{
		if (**format == '*')
		{
			k->w_n = va_arg(ap, int);
			if (k->w_n < 0)
			{
				k->w_n *= -1;
				k->minus = 1;
			}
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			k->w_n = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
	}
}

void	fck_preco(va_list ap, const char **format, t_eb *k)
{
	k->prec = 1;
	while ((ft_isdigit(**format)) || (**format == '*') || (**format ==  '.'))
	{
		while (**format == '.')
			(*format)++;
		if (**format == '*')
		{
			k->p_n = va_arg(ap, int);
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			k->p_n = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else
			k->p_n = 0;
	}
}

void	found_ignored(t_eb *k, const char **format)
{
	if (k->plus && k->space)
		k->space = 0;
	if (((k->minus) || ((k->prec) && (**format != 's'))) && (k->zero))
		k->zero = 0;


}
