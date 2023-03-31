/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:38:21 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/03/31 16:43:29 by hdagdagu         ###   ########.fr       */
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

void	my_sleep(unsigned int sleep, t_philo *philo)
{
	long	time;
	long	start;

	(void)philo;
	time = 0;
	start = current_time();
	while (time < sleep)
	{
		time = current_time() - start;
		usleep(100);
	}
}

void	init_mutex(t_philo *philo, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (i < philo->num)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
}

void	init_argv(t_philo *philo, int i, char **argv, int argc)
{

	philo[i].num = ft_atoi(argv[1]);
	philo[i].die = ft_atoi(argv[2]);
	philo[i].eat = ft_atoi(argv[3]);
	philo[i].sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo[i].must_eat = ft_atoi(argv[5]);
	else
		philo[i].must_eat = -1;
}

void	initialize_arg(t_philo *philo, char **argv, int argc)
{
	int			i;
	long		creating;
	static int	check;
	static int	total;
	static pthread_mutex_t	print;
	static pthread_mutex_t	data_race;

	pthread_mutex_init(&print, NULL);
	pthread_mutex_init(&data_race, NULL);
	i = 0;
	check = FALSE;
	creating = current_time();
	while (i < ft_atoi(argv[1]))
	{
		philo[i].total = &total;
		philo[i].id = i;
		philo[i].check = &check;
		philo[i].creating_time = creating;
		philo[i].last_eat = creating;
		philo[i].data_race = &data_race;
		philo[i].print = &print;
		init_argv(philo, i, argv, argc);
		i++;
	}
}
