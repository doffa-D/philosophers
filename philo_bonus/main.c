/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:50:44 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/04 17:45:32 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (check_arg(argc, argv))
		return (FALSE);
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philo)
		return (FALSE);
	initialize_arg(philo, argv, argc);
	if (philosopher(philo) == 1)
	{
		printf("ERORR: Protection !!\n");
		kill_process_b(philo);
		return (1);
	}
	kill_process_b(philo);
	return (TRUE);
}
