/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:28:48 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/19 13:28:46 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_error(void)
{
	printf("Error in Params please enter: num_philo\
	time_die time_eat time_sleep (num_eat)\n");
}

void	free_param(t_philo *philo_data, pthread_t *philo, pthread_mutex_t *fork)
{
	free(philo_data);
	free(philo);
	free(fork);
}

void	my_usleep(unsigned int usec)
{
	long	start_time;
	long	current_time;
	long	time;

	start_time = get_current_time();
	time = 0;
	while (time < usec)
	{
		current_time = get_current_time();
		time = current_time - start_time;
		usleep(100);
	}
}

int	quick_check(t_philo *philo_data, int num, pthread_mutex_t *protect_philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (philo_data[i].philo_total_eat == num)
		{
			printf("Philo has finished eating\n");
			destroy_mu(philo_data, num);
			return (0);
		}
		if (get_current_time()
			- philo_data[i].last_eat >= philo_data->philo_die)
		{
			pthread_mutex_lock(protect_philo);
			printf("%ld %d died\n", get_current_time()
				- philo_data[i].first_eat, philo_data->id);
			pthread_mutex_unlock(protect_philo);
			destroy_mu(philo_data, num);
			return (0);
		}
		i = (i + 1) % num;
		usleep(30);
	}
	return (0);
}
