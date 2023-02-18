/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:56:07 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/18 20:09:04 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pthread(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %d has taken a fork\n", get_current_time() - philo->first_eat,
		philo->id);
	pthread_mutex_lock(philo->right_fork);
	printf("%ld %d has taken a fork\n", get_current_time() - philo->first_eat,
		philo->id);
	printf("%ld %d is eating\n", get_current_time() - philo->first_eat,
		philo->id);
}

void	*philosopher(void *ptr)
{
	t_philo	*philo;
	int		eating_count;

	philo = (t_philo *)ptr;
	eating_count = 0;
	if (philo->id % 2 == 1)
		usleep(300);
	while (1)
	{
		pthread(philo);
		philo->last_eat = get_current_time();
		eating_count++;
		my_usleep(philo->philo_eat);
		if (eating_count >= philo->philo_must_eat)
			philo->philo_total_eat++;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		printf("%ld %d is sleeping\n", get_current_time() - philo->first_eat,
			philo->id);
		my_usleep(philo->philo_sleep);
		printf("%ld %d is thinking\n", get_current_time() - philo->first_eat,
			philo->id);
	}
	return (NULL);
}

void	destroy_mu(t_philo *philo_data, int num)
{
	int	i;

	i = 0;
	while (i < num)
		pthread_mutex_destroy(&philo_data->left_fork[i++]);
}

int	check(t_philo *philo_data, t_const *philo_const, pthread_t *philo)
{
	int	i;

	i = 0;
	while (i < philo_const->num)
	{
		if (pthread_create(&philo[i], NULL, philosopher, &philo_data[i]) != 0)
		{
			printf("Pthread_create field\n");
			return (1);
		}
		usleep(100);
		i++;
	}
	if (quick_check(philo_data, philo_const->num) == 0)
		return (0);
	i = 0;
	while (i < philo_const->num)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	return (0);
}
