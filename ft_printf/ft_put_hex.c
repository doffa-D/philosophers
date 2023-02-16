/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:14:20 by hdagdagu          #+#    #+#             */
/*   Updated: 2022/10/18 23:47:42 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int hex)
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
		return (i);
	}
}

int	ft_put_hex(unsigned int hex, char d)
{
	if (hex == 0)
		return (write(1, "0", 1));
	if (hex >= 16)
	{
		ft_put_hex(hex / 16, d);
		ft_put_hex(hex % 16, d);
	}
	else
	{
		if (hex <= 9)
		{
			ft_putchar(hex + 48);
		}
		else
		{
			if (d == 'x')
				ft_putchar(hex - 10 + 'a');
			else if (d == 'X')
				ft_putchar(hex - 10 + 'A');
		}
	}
	return (ft_hex_len(hex));
}
