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

void	found_preco(t_eb *k)
{
	char 	*tmp;
	int		i;

	i = 0;
	k->pcount = (int)((k->p_n) - (ft_strlen(k->dst)) + k->neg);
	if (k->pcount <= 0 && !(k->pcount = 0))
		return ;
	tmp = ft_strnew((size_t)k->pcount);
	while (k->pcount--)
		tmp[i++] = '0';
	if (k->neg)
	{
		k->dst = ft_strjoin(tmp, k->dst + 1);
		k->dst = ft_strjoin("-", k->dst);
	}
	else
		k->dst = ft_strjoin(tmp, k->dst);
}

void	found_width(t_eb *k, const char **format, int flag)
{
	k->wcount = (int)((k->w_n) - (ft_strlen(k->dst)) - flag);
	if (k->wcount <= 0 && !(k->wcount = 0))
		return ;
	if (k->minus == 1)
		print_yminus(k, format);
	else if (k->minus == 0 && !(k->zero))
		print_nminus(k, format);
	if ((k->zero) && !(k->space))
		print_zero(k, format);
	else if ((k->zero) && (k->space))
		print_zero(k, format);

}


void	print_zero(t_eb *k, const char **format)
{
	if (k->plus && !(k->neg))
	{
		ft_putchar('+');
		k->outn++;
	}
	if (k->space && !(k->neg))
		ft_putchar(' ');
	if (k->neg)
		ft_putchar('-');
	while (k->wcount--)
		write(1, "0", 1);
	((k->space) && !(k->neg)) ? ft_putstr(k->dst) : ft_putstr(k->dst + 1);
	k->outn += ft_strlen(k->dst);
}

void	print_nminus(t_eb *k, const char **format)
{
	while (k->wcount-- && write(1, " ", 1))
		k->outn++;
	if ((k->space && !(k->neg)) ? k->outn++ : 0)
		ft_putchar(' ');
	if ((k->plus && !(k->neg)) ? k->outn++ : 0)
		ft_putchar('+');
	ft_putstr(k->dst);
	k->outn += ft_strlen(k->dst);
}

void	print_yminus(t_eb *k, const char **format)
{
	if (k->plus && !(k->neg))
	{
		ft_putchar('+');
		k->outn++;
	}

	if (k->space && !(k->neg))
	{
		ft_putchar(' ');
		k->outn++;
	}
	ft_putstr(k->dst);
	k->outn += ft_strlen(k->dst);
	while (k->wcount--)
	{
		write(1, " ", 1);
		k->outn++;
	}
}

void	print_wany(t_eb *k)
{
	if (k->plus && !(k->neg))
	{
		ft_putchar('+');
		k->outn++;
	}
	if (k->space && !(k->neg))
	{
		ft_putchar(' ');
		k->outn++;
	}
	ft_putstr(k->dst);
	k->outn += ft_strlen(k->dst);
}

void	hash_func(t_eb *k, const char **format)
{

}