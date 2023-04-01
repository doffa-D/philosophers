/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:06:50 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/01 15:53:24 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	putting_fork(sem_t *fork, t_philo *philo)
{
	sem_post(fork);
	sem_post(fork);
	philo->total++;
	if ((philo->total) == philo->must_eat)
	{
		usleep(10000);
		kill_process_b(philo);
		exit(0);
	}
}

int	taking_fork(t_philo *philo, sem_t *fork)
{
	sem_wait(fork);
	print(philo, "has taken a fork\n", current_time() - philo->creating_time);
	if (philo->num == 1)
		return (1);
	sem_wait(fork);
	print(philo, "has taken a fork\n", current_time() - philo->creating_time);
	return (0);
}

void	eating(t_philo *philo, sem_t *data_race)
{
	sem_wait(data_race);
	philo->last_eat = current_time();
	sem_post(data_race);
	print(philo, "is eating\n", current_time() - philo->creating_time);
	my_sleep(philo->eat);
}

void	sleeping(t_philo *philo)
{
	print(philo, "is sleeping\n", current_time() - philo->creating_time);
	my_sleep(philo->sleep);
	print(philo, "is thinking\n", current_time() - philo->creating_time);
}

void	rotine(t_philo *philo, sem_t *fork)
{
	pthread_t	thread;

	philo->name = ft_itoa(philo->id);
	sem_unlink(philo->name);
	philo->data_race = sem_open(philo->name, O_CREAT | O_EXCL, 0644, 1);
	free(philo->name);
	pthread_create(&thread, NULL, check_rotin, philo);
	while (1)
	{
		if (taking_fork(philo, fork) == 1)
			break ;
		eating(philo, philo->data_race);
		putting_fork(fork, philo);
		sleeping(philo);
	}
	pthread_join(thread, NULL);
}
