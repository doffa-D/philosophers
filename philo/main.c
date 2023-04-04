/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:50:44 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/04 17:04:47 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo		*philo;
	pthread_t	*faylasof;

	if (check_arg(argc, argv))
		return (FALSE);
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	faylasof = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	if (!philo || !faylasof)
		return (FALSE);
	initialize_arg(philo, argv, argc);
	create_fork(philo);
	philosopher(philo, faylasof);
	return (TRUE);
}
