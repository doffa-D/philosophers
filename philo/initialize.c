/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:38:21 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/04 16:05:22 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_sleep(unsigned int sleep)
{
	long	time;
	long	start;

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
	(void)fork;
	while (i < philo->num)
	{
		if (pthread_mutex_init(&fork[i], NULL) != 0)
		{
			printf("ERORR: Protection !!\n");
			break ;
		}
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

int	initia(t_philo *philo, char **argv)
{
	static pthread_mutex_t	data_race;
	static pthread_mutex_t	print;
	int						i;

	i = 0;
	if (pthread_mutex_init(&print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data_race, NULL) != 0)
		return (1);
	while (i < ft_atoi(argv[1]))
	{
		philo[i].data_race = &data_race;
		philo[i].print = &print;
		i++;
	}
	return (0);
}

void	initialize_arg(t_philo *philo, char **argv, int argc)
{
	int			i;
	long		creating;
	static int	check;
	static int	total;

	i = 0;
	check = FALSE;
	creating = current_time();
	if (initia(philo, argv) != 0)
		return ;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].total = &total;
		philo[i].id = i + 1;
		philo[i].check = &check;
		philo[i].creating_time = creating;
		philo[i].last_eat = creating;
		init_argv(philo, i, argv, argc);
		i++;
	}
}
