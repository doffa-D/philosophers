/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:55:17 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/12 14:43:07 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_philo
{
	int id;
	int x;
	int philo_die;
    int philo_eat;
    int philo_sleep;
	int philo_must_eat;
	long first_eat;
	long last_eat;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
}	t_philo;

#endif