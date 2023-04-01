/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:45:19 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/01 15:49:17 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_is_digit(char **av, int ac)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (ac > i && av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j++]) == 0)
			{
				printf("error\n");
				return (FALSE);
			}
		}
		i++;
	}
	return (TRUE);
}

int	check_arg(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("Usage: ./philo <number_of_philos> <time_to_die> <time_to_eat> \
		 <time_to_sleep> [number_of_times_eacih_philosopher_must_eat]\n");
		return (FALSE);
	}
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0
		|| ft_atoi(av[4]) <= 0 || check_is_digit(av, ac) == FALSE)
	{
		printf("ERROR\n");
		return (FALSE);
	}
	if (av[5])
	{
		if (ft_atoi(av[5]) <= 0)
		{
			printf("ERROR\n");
			return (FALSE);
		}
	}
	return (TRUE);
}

void	print(t_philo *philo, char *str, long time)
{
	int		check;

	pthread_mutex_lock(philo->data_race);
	check = *(philo->check);
	pthread_mutex_unlock(philo->data_race);
	if (check)
	{
		pthread_mutex_lock(philo->print);
		printf("%ld %d %s", time, philo->id + 1, str);
		pthread_mutex_unlock(philo->print);
	}
}
