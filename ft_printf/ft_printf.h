/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:25:11 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/01/31 18:43:41 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *src, ...);
int		ft_put_hex(unsigned int hex, char d);
int		ft_unsi_putnbr(unsigned int n);
int		ft_put_addp(unsigned long hex, char d);
int		ft_putchar(int c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);

#endif
