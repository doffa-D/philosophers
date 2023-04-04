/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:46:41 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/04 15:39:04 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time(void)
{
	struct timeval	start;
	long			my_time;

	gettimeofday(&start, NULL);
	my_time = (start.tv_sec) * 1000 + (start.tv_usec) / 1000;
	return (my_time);
}

void	thread_join(pthread_t *faylasof, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].num)
	{
		if (pthread_join(faylasof[i], NULL) != 0)
		{
			printf("ERORR: Protection !!\n");
			break ;
		}
		i++;
	}
	free_all(faylasof, philo);
}

void	philosopher(t_philo *philo, pthread_t *faylasof)
{
	creating_tread(faylasof, philo);
	if (check_rotin(philo) != 0)
		printf("ERORR: Protection !!\n");
	thread_join(faylasof, philo);
}

void	create_fork(t_philo *philo)
{
	int				i;
	pthread_mutex_t	*fork;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * philo[i].num);
	init_mutex(philo, fork);
	while (i < philo[0].num)
	{
		philo[i].right_fork = &fork[i];
		philo[i].left_fork = &fork[(i + 1) % philo[0].num];
		i++;
	}
}

void	creating_tread(pthread_t *faylasof, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].num)
	{
		if (pthread_create(&faylasof[i], NULL, rotin, &philo[i]) != 0)
		{
			printf("ERORR: Protection !!\n");
			break ;
		}
		usleep(10);
		i++;
	}
}
