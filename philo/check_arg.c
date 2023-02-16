/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:28:48 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/16 18:35:16 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return ((start.tv_sec) * 1000 + (start.tv_usec) / 1000);
}


int	check_arg(t_const *philo_const)
{
	if (philo_const->argc < 5)
	{
		exit_error();
		return (1);
	}
	if (is_int(philo_const->argv) == 1)
		return (1);
	if (ft_atoi(philo_const->argv[2]) <= 0 || ft_atoi(philo_const->argv[3]) <= 0
		|| ft_atoi(philo_const->argv[4]) <= 0
		|| ft_atoi(philo_const->argv[1]) <= 0)
	{
		printf("error\n");
		return (1);
	}
	if (philo_const->argc == 6)
	{
		if (ft_atoi(philo_const->argv[5]) <= 0)
		{
			printf("error\n");
			return (1);
		}
	}
	return (0);
}

void	arg_int(t_philo *philo_data, t_const *philo_const,
		pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (i < philo_const->num)
		pthread_mutex_init(&fork[i++], NULL);
	i = 0;
	while (i < philo_const->num)
	{
		philo_data[i].id = i;
		philo_data[i].first_eat = philo_const->start_time;
		philo_data[i].last_eat = philo_const->start_time;
		philo_data[i].philo_die = ft_atoi(philo_const->argv[2]);
		philo_data[i].philo_eat = ft_atoi(philo_const->argv[3]);
		philo_data[i].philo_sleep = ft_atoi(philo_const->argv[4]);
		if (philo_const->argc == 6)
			philo_data[i].philo_must_eat = ft_atoi(philo_const->argv[5]);
		else
			philo_data[i].philo_must_eat = INT_MAX;
		philo_data[i].left_fork = &fork[i];
		philo_data[i].right_fork = &fork[(i + 1) % philo_const->num];
		i++;
	}
}

int	is_int(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
