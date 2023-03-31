/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:36:31 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/03/31 17:06:09 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	putting_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

int	taking_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print(philo, "has taken a fork\n", current_time() - philo->creating_time);
	if (philo->num == 1)
		return (1);
	pthread_mutex_lock(philo->left_fork);
	print(philo, "has taken a fork\n", current_time() - philo->creating_time);
	return (0);
}

int	eating(t_philo *philo, int counter)
{
	print(philo, "is eating\n", current_time() - philo->creating_time);
	pthread_mutex_lock(philo->data_race);
	philo->last_eat = current_time();
	pthread_mutex_unlock(philo->data_race);
	counter++;
	if (counter == philo->must_eat)
		*(philo->total) += 1;
	my_sleep(philo->eat, philo);
	return (counter);
}

void	sleeping(t_philo *philo)
{
	print(philo, "is sleeping\n", current_time() - philo->creating_time);
	my_sleep(philo->sleep, philo);
	print(philo, "is thinking\n", current_time() - philo->creating_time);
}

void	*rotin(void *s)
{
	t_philo	*philo;
	int		counter;
	int		check;

	counter = 0;
	check = 1;
	philo = (t_philo *)s;
	if ((philo->id) % 2 == 1)
		usleep(300);
	while (check)
	{
		pthread_mutex_lock(philo->data_race);
		check = *philo->check;
		pthread_mutex_unlock(philo->data_race);
		if (taking_fork(philo) == 1 || *(philo->total) == philo->num)
		{
			putting_fork(philo);
			break ;
		}
		counter = eating(philo, counter);
		putting_fork(philo);
		sleeping(philo);
	}
	return (NULL);
}
