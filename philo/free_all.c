/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:47:35 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/04 15:09:37 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(pthread_t *faylasof, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].num)
	{
		if (pthread_mutex_destroy(&philo->right_fork[i]) != 0)
		{
			printf("ERORR: Protection !!\n");
			return ;
		}
		i++;
	}
	if (pthread_mutex_destroy(philo->print) != 0
		|| pthread_mutex_destroy(philo->data_race) != 0)
	{
		printf("ERORR: Protection !!\n");
		return ;
	}
	free(faylasof);
	free(philo->right_fork);
	free(philo);
}
