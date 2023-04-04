/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:53:55 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/04 16:02:01 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mini_rotine(t_philo *philo, int check, int counter, int take)
{
	while (check)
	{
		if (pthread_mutex_lock(philo->data_race) != 0)
			return (1);
		check = *philo->check;
		if (pthread_mutex_unlock(philo->data_race) != 0)
			return (1);
		take = taking_fork(philo);
		if (take == -1)
			return (1);
		if (take == -1 || *(philo->total) == philo->num)
		{
			if (putting_fork(philo) != 0)
				return (1);
			break ;
		}
		counter = eating(philo, counter);
		if (counter == -1)
			return (1);
		if (putting_fork(philo) != 0)
			return (1);
		sleeping(philo);
	}
	return (0);
}

void	*rotin(void *s)
{
	t_philo	*philo;
	int		counter;
	int		check;
	int		take;

	counter = 0;
	check = 1;
	take = 0;
	philo = (t_philo *)s;
	if ((philo->id) % 2 == 0)
		usleep(300);
	if (mini_rotine(philo, check, counter, take) != 0)
		return ((void *)1);
	else
		return (0);
}
