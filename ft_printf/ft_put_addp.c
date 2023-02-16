/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_addp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:14:20 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/10/18 23:47:47 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexx_len(unsigned long hex)
{
	int	i;

	i = 0;
	if (hex == 0)
		return (0);
	else
	{
		while (hex != 0)
		{
			i++;
			hex = hex / 16;
		}
	}
	return (i);
}

int	ft_put_addp(unsigned long hex, char d)
{
	if (d == 'p')
	{
		write(1, "0x", 2);
		if (hex == 0)
			return (2 + write(1, "0", 1));
		d = 'o';
	}
	if (hex >= 16)
	{
		ft_put_addp(hex / 16, d);
		ft_put_addp(hex % 16, d);
	}
	else
	{
		if (hex <= 9)
			ft_putchar(hex + 48);
		else
			if (d == 'o')
				ft_putchar(hex - 10 + 'a');
	}
	return (2 + ft_hexx_len(hex));
}
