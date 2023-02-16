/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsi_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:11:58 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/10/18 16:55:34 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_coute(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_unsi_putnbr(unsigned int n)
{
	if (n >= 0 && n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_unsi_putnbr(n / 10);
		ft_unsi_putnbr(n % 10);
	}
	return (ft_coute(n));
}
