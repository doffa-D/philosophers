/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:36:31 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/04 15:54:56 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	putting_fork(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->right_fork) != 0)
		return (1);
	if (pthread_mutex_unlock(philo->left_fork) != 0)
		return (1);
	return (0);
}

int	taking_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->right_fork) != 0)
		return (1);
	if (print(philo, "has taken a fork\n", current_time()
			- philo->creating_time) != 0)
		return (1);
	if (philo->num == 1)
		return (-1);
	if (pthread_mutex_lock(philo->left_fork) != 0)
		return (1);
	if (print(philo, "has taken a fork\n", current_time()
			- philo->creating_time) != 0)
		return (1);
	return (0);
}

int	eating(t_philo *philo, int counter)
{
	if (print(philo, "is eating\n", current_time() - philo->creating_time) != 0)
		return (-1);
	if (pthread_mutex_lock(philo->data_race) != 0)
		return (-1);
	philo->last_eat = current_time();
	if (pthread_mutex_unlock(philo->data_race) != 0)
		return (-1);
	counter++;
	if (counter == philo->must_eat)
		*(philo->total) += 1;
	my_sleep(philo->eat);
	return (counter);
}

int	sleeping(t_philo *philo)
{
	if (print(philo, "is sleeping\n", current_time()
			- philo->creating_time) != 0)
		return (-1);
	my_sleep(philo->sleep);
	if (print(philo, "is thinking\n", current_time()
			- philo->creating_time) != 0)
		return (-1);
	return (0);
}
