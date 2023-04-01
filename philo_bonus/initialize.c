/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:07:32 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/01 15:55:40 by hdagdagu         ###   ########.fr       */
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
	sem_t		*print;

	sem_unlink("/my_print");
	print = sem_open("/my_print", O_CREAT | O_EXCL, 0644, 1);
	i = 0;
	check = FALSE;
	creating = current_time();
	while (i < ft_atoi(argv[1]))
	{
		philo[i].print = print;
		philo[i].id = i;
		philo[i].total = 0;
		philo[i].check = &check;
		philo[i].creating_time = creating;
		philo[i].last_eat = creating;
		init_argv(philo, i, argv, argc);
		i++;
	}
}
