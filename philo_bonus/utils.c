/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:31:21 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/03/30 17:51:54 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sing;

	result = 0;
	sing = 1;
	i = 0;
	while ((str[i] == 32) || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\r') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	return (result * sing);
}



int	ft_counte(long int nb)
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

char	*ft_itoa(int n)
{
	char		*dst;
	long int	nb;
	int			len;

	nb = n;
	len = ft_counte(nb);
	dst = malloc(len +1);
	if (!dst)
		return (0);
	if (nb < 0)
	{
		dst[0] = '-';
		nb *= -1;
	}
	dst[len] = 0;
	if (nb == 0)
		dst[0] = '0';
	while (nb != 0)
	{
		dst[--len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (dst);
}