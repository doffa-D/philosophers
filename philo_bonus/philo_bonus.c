/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:27:35 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/19 13:00:57 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_process_b(int *pid, int num, sem_t *philo_fork)
{
	int	i;

	i = 1;
	while (i <= num)
	{
		kill(pid[i], SIGINT);
		i++;
	}
	sem_unlink("/my_forks");
	sem_close(philo_fork);
}

void	arg_int_bonus(t_philo *philo_data, t_const *philo_const)
{
	long	start;

	start = get_current_time();
	philo_data->first_eat = start;
	philo_data->last_eat = start;
	philo_data->philo_die = ft_atoi(philo_const->argv[2]);
	philo_data->philo_eat = ft_atoi(philo_const->argv[3]);
	philo_data->philo_sleep = ft_atoi(philo_const->argv[4]);
	if (philo_const->argc == 6)
		philo_data->philo_must_eat = ft_atoi(philo_const->argv[5]);
	else
		philo_data->philo_must_eat = INT_MAX;
}
