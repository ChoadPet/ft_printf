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
	int 	count;
	char 	*tmp;
	int		i;

	i = 0;
	(k->dst[0] == '-') ? (k->neg = 1) : (k->neg = 0);
	count = (int)((k->p_n) - (ft_strlen(k->dst)) + k->neg);
	if (count <= 0)
		return ;
	tmp = ft_strnew((size_t)count);
	while (count--)
		tmp[i++] = '0';
	if (k->neg)
	{
		k->dst = ft_strjoin(tmp, k->dst + 1);
		k->dst = ft_strjoin("-", k->dst);
	}
	else
		k->dst = ft_strjoin(tmp, k->dst);
}

void	found_width(t_eb *k)
{
	k->scount = (int)((k->w_n) - (ft_strlen(k->dst)));
	if (k->scount <= 0)
		k->scount = 0;
}