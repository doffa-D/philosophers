/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:06:50 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/04 17:43:38 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	putting_fork(sem_t *fork, t_philo *philo)
{
	if (sem_post(fork) == -1)
		return (1);
	if (sem_post(fork) == -1)
		return (1);
	philo->total++;
	if ((philo->total) == philo->must_eat)
	{
		usleep(10000);
		kill_process_b(philo);
		exit(0);
	}
	return (0);
}

int	taking_fork(t_philo *philo, sem_t *fork)
{
	if (sem_wait(fork) == -1)
		return (-1);
	if (print(philo, "has taken a fork\n", current_time()
			- philo->creating_time) == 1)
		return (1);
	if (philo->num == 1)
		return (1);
	if (sem_wait(fork) == -1)
		return (-1);
	if (print(philo, "has taken a fork\n", current_time()
			- philo->creating_time) == 1)
		return (1);
	return (0);
}

int	eating(t_philo *philo, sem_t *data_race)
{
	if (sem_wait(data_race) == -1)
		return (1);
	philo->last_eat = current_time();
	if (sem_post(data_race) == -1)
		return (1);
	if (print(philo, "is eating\n", current_time() - philo->creating_time) == 1)
		return (1);
	my_sleep(philo->eat);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (print(philo, "is sleeping\n", current_time()
			- philo->creating_time) == 1)
		return (1);
	my_sleep(philo->sleep);
	if (print(philo, "is thinking\n", current_time()
			- philo->creating_time) == 1)
		return (1);
	return (0);
}
