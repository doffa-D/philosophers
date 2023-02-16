/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:54:41 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/16 19:07:39 by hdagdagu         ###   ########.fr       */
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
		pthread_create(&philo[i], NULL, philosopher, &philo_data[i]);
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

int	main(int argc, char **argv)
{
	int				i;
	t_philo			*philo_data;
	pthread_t		*philo;
	pthread_mutex_t	*fork;
	t_const			philo_const;

	i = 0;
	philo_const.argc = argc;
	philo_const.argv = argv;
	if (check_arg(&philo_const) == 1)
		return (1);
	philo_const.num = ft_atoi(argv[1]);
	philo_const.start_time = get_current_time();
	philo_data = malloc(sizeof(t_philo) * philo_const.num);
	philo = malloc(sizeof(pthread_t) * philo_const.num);
	fork = malloc(sizeof(pthread_mutex_t) * philo_const.num);
	arg_int(philo_data, &philo_const, fork);
	if (check(philo_data, &philo_const, philo) == 0)
	{
		free_param(philo_data, philo, fork);
		return (0);
	}
	free_param(philo_data, philo, fork);
	return (0);
}
