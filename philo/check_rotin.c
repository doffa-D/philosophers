/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:39:55 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/03/31 17:47:32 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_must_eat(t_philo *philo, int i)
{
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->print);
	*(philo[i].check) = TRUE;
	pthread_mutex_unlock(philo->print);
}

int	check_rotin(t_philo *philo, int num)
{
	int		i;
	long	time;
	long	eat;

	time = 0;
	i = 0;
	eat = 0;
	while (*(philo[i].check))
	{
		time = current_time();
		pthread_mutex_lock(philo[i].data_race);
		eat = philo[i].last_eat;
		pthread_mutex_unlock(philo[i].data_race);
		if (time - eat >= philo[i].die)
		{
			pthread_mutex_lock(philo[i].data_race);
			*(philo[i].check) = TRUE;
			pthread_mutex_unlock(philo[i].data_race);
			printf("%ld %d died\n",time - eat,philo[i].id);
		}
		if (*(philo[i].total) == philo->num)
			check_must_eat(philo, i);
		i = (i + 1) % num;
	}
	return (0);
}
