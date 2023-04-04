/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:39:55 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/04 16:01:25 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_must_eat(t_philo *philo, int i)
{
	if (pthread_mutex_unlock(philo->print) != 0)
		return (1);
	if (pthread_mutex_lock(philo->print) != 0)
		return (1);
	*(philo[i].check) = TRUE;
	if (pthread_mutex_unlock(philo->print) != 0)
		return (1);
	return (0);
}

int	check(t_philo *philo, long eat, long time, int i)
{
	while (*(philo[i].check))
	{
		time = current_time();
		if (pthread_mutex_lock(philo[i].data_race) != 0)
			return (1);
		eat = philo[i].last_eat;
		if (pthread_mutex_unlock(philo[i].data_race) != 0)
			return (1);
		if (time - eat >= philo[i].die)
		{
			if (pthread_mutex_lock(philo[i].data_race) != 0)
				return (1);
			*(philo[i].check) = TRUE;
			if (pthread_mutex_unlock(philo[i].data_race) != 0)
				return (1);
			pthread_mutex_unlock(philo[i].data_race);
			printf("%ld %d died\n", time - eat, philo[i].id);
		}
		if (*(philo[i].total) == philo->num)
			if (check_must_eat(philo, i) == 1)
				return (1);
		i = (i + 1) % philo->num;
	}
	return (0);
}

int	check_rotin(t_philo *philo)
{
	int		i;
	long	time;
	long	eat;

	time = 0;
	i = 0;
	eat = 0;
	if (check(philo, eat, time, i) != 0)
		return (1);
	return (0);
}
