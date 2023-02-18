/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:44:38 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/18 13:21:04 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
#include <semaphore.h>
#include <signal.h>
#include "../philo/philo.h"


typedef struct s_check
{
	int philo_total_eat;
	int pid;
	long last_eat;
	int philo_die;
	int id;
	long first_eat;
	sem_t *fork;
}					t_check;

#endif