/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:50:44 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/03/31 16:28:43 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc,char **argv)
{
	t_philo *philo;
	
	if(check_arg(argc,argv))
	    return(FALSE);
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if(!philo)
		return (FALSE);
	initialize_arg(philo,argv,argc);

	philosopher(philo);
	kill_process_b(philo);
	return (TRUE);
}