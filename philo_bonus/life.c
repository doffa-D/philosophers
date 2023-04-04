/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:42:49 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/04 17:44:58 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mini_rotine(t_philo *philo, sem_t *fork)
{
	int	n;

	n = 0;
	while (1)
	{
		n = taking_fork(philo, fork);
		if (n == 1)
			break ;
		else if (n == -1)
			return (1);
		if (eating(philo, philo->data_race) == 1)
			return (1);
		if (putting_fork(fork, philo) == 1)
			return (1);
		if (sleeping(philo) == 1)
			return (1);
	}
	return (0);
}

int	rotine(t_philo *philo, sem_t *fork)
{
	pthread_t	thread;

	philo->name = ft_itoa(philo->id);
	if (sem_unlink(philo->name) == -1)
		return (1);
	philo->data_race = sem_open(philo->name, O_CREAT | O_EXCL, 0644, 1);
	free(philo->name);
	if (pthread_create(&thread, NULL, check_rotin, philo) != 0)
		return (1);
	if (mini_rotine(philo, fork) == 1)
		return (1);
	if (pthread_join(thread, NULL) != 0)
		return (1);
	return (0);
}
