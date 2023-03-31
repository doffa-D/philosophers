/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:08:48 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/03/31 18:26:37 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	kill_process_b(t_philo *philo)
{
	int	i;
	i = 0;
	while (i <= philo[0].num)
	{
		kill(philo[i].pid, SIGINT);
		usleep(200000);
		i++;
	}
	sem_close(philo->fork);
	sem_close(philo->print);
	sem_close(philo->data_race);
    free(philo);
}


void	print(t_philo *philo, char *str, long time)
{
	sem_wait(philo->print);
	printf("%ld %d %s", time, philo->id + 1, str);
	sem_post(philo->print);
}


void	*check_rotin(void *arg)
{
	t_philo	*philo;
	long time;
	long last;

	philo = arg;
	while (1)
	{
		sem_wait(philo->data_race);
		time = current_time();
		last = philo->last_eat;
		sem_post(philo->data_race);
		if (time - last >= philo->die)
		{
			usleep(100);
			sem_wait(philo->print);
			printf("%ld %d died\n",time - philo->creating_time,philo->id);
			kill_process_b(philo);
			exit(1);
		}
	}
	return (NULL);
}

void	philosopher(t_philo *philo)
{
	int i;
	pid_t	pid;

	sem_unlink("/my_forks");
	sem_unlink("/my_print");
	philo->fork = sem_open("/my_forks", O_CREAT | O_EXCL, 0644, philo->num);
	i = 0;
	while(i < philo->num)
	{
		pid = fork();
		if(pid == 0)
		{
			rotine(&philo[i],philo->fork);
		}
		else
			philo[i].pid = pid;
		i++;
		usleep(10);
	}
	waitpid(-1, &pid, 0);
}