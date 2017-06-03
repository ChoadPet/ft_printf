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

void	found_width(t_eb *k)
{

}

void	found_waminus(t_eb *k)
{

}

void	found_preco(t_eb *k)
{
	char 	*tmp;
	int 	count;
	int		i;

	i = 0;
	count = (int)((k->p_n) - (ft_strlen((size_t)k->dst)));
	if (count <= 0)
		return ;
	tmp = ft_strnew((size_t)count);
	while (count--)
		tmp[i++] = '0';
	k->dst = ft_strjoin(tmp, k->dst);
}

//void	found_spreco(t_eb *k)
//{
//	if (k->p_n == 0)
//		k->dst = NULL;
//
//}
