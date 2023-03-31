/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:47:35 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/03/31 16:48:01 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(pthread_t *faylasof, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].num)
		pthread_mutex_destroy(&philo->right_fork[i++]);
	pthread_mutex_destroy(philo->print);
	pthread_mutex_destroy(philo->data_race);
	free(faylasof);
	free(philo->right_fork);
	free(philo);
}
