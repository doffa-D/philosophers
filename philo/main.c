/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:54:41 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/18 20:08:51 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			*philo_data;
	pthread_t		*philo;
	pthread_mutex_t	*fork;
	t_const			philo_const;

	philo_const.argc = argc;
	philo_const.argv = argv;
	if (check_arg(&philo_const) == 1)
		return (1);
	philo_const.num = ft_atoi(argv[1]);
	philo_const.start_time = get_current_time();
	philo_data = malloc(sizeof(t_philo) * philo_const.num);
	philo = malloc(sizeof(pthread_t) * philo_const.num);
	fork = malloc(sizeof(pthread_mutex_t) * philo_const.num);
	if (!fork || !philo_data || !philo)
		return (NULL);
	arg_int(philo_data, &philo_const, fork);
	if (check(philo_data, &philo_const, philo) == 0)
	{
		free_param(philo_data, philo, fork);
		return (0);
	}
	free_param(philo_data, philo, fork);
	return (0);
}
