/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:44:38 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/19 12:00:55 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include "../philo/philo.h"
# include <semaphore.h>
# include <signal.h>

typedef struct s_check
{
	int		*pid;
	long	last_eat;
	int		philo_die;
	int		id;
	int		num;
	long	first_eat;
	int		eating_count;
	sem_t	*fork;
}			t_check;

void		kill_process_b(int *pid, int num, sem_t *philo_fork);
void		arg_int_bonus(t_philo *philo_data, t_const *philo_const);

#endif