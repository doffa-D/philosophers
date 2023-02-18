/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:44:33 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/18 13:38:08 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
// long	get_current_time(void)
// {
// 	struct timeval	start;

// 	gettimeofday(&start, NULL);
// 	return ((start.tv_sec) * 1000 + (start.tv_usec) / 1000);
// }

void	kill_process(int *pid,t_const *philo_const)
{
	int i;
	i = 0;
	sem_unlink("my_forks");
	while(i < philo_const->num)
	{
		kill(pid[i], SIGINT);
		i++;
	}
}


void	arg_int_bonus(t_philo *philo_data, t_const *philo_const)
{
	long start = get_current_time();
	philo_data->first_eat = start;
	philo_data->last_eat = start;
	philo_data->philo_die = ft_atoi(philo_const->argv[2]);
	philo_data->philo_eat = ft_atoi(philo_const->argv[3]);
	philo_data->philo_sleep = ft_atoi(philo_const->argv[4]);
	if (philo_const->argc == 6)
		philo_data->philo_must_eat = ft_atoi(philo_const->argv[5]);
	else
		philo_data->philo_must_eat = INT_MAX;
}

void *check_death(void *data)
{
    t_check *philo_data = (t_check *)data;
    while (1)
    {
		long new = get_current_time();
        if (new  - philo_data->last_eat >= philo_data->philo_die)
        {
            printf("%ld %d died\n", get_current_time() - philo_data->first_eat, philo_data->id);
            sem_close(philo_data->fork);
            sem_unlink("my_forks");
            kill(philo_data->pid, SIGINT);
            exit(1);
        }
        usleep(10);
    }
    return (NULL);
}

void	philosopher_bonus(sem_t *philo_fork,t_philo *philo_data,t_const *philo_const,int i,int pid)
{

	int eating_count;
	eating_count = 0;
	(void)philo_const;
	pthread_t thread;
	t_check check;
	while(1)
	{
		sem_wait(philo_fork);
		printf("%ld %d has taken a fork\n", get_current_time() - philo_data->first_eat,i);
		sem_wait(philo_fork);
		printf("%ld %d has taken a fork\n", get_current_time() - philo_data->first_eat,i);
		printf("%ld %d is eating\n", get_current_time() - philo_data->first_eat,i);
		philo_data->last_eat = get_current_time();
		eating_count++;
		my_usleep(philo_data->philo_eat);
		if(eating_count >= philo_data->philo_must_eat)
			philo_data->philo_total_eat++;
		sem_post(philo_fork);
		sem_post(philo_fork);
		check.first_eat = philo_data->first_eat;
		check.philo_total_eat = philo_data->philo_total_eat;
		check.pid = pid;
		check.fork = philo_fork;
		check.last_eat = philo_data->last_eat;
		check.philo_die = philo_data->philo_die;
		check.id = i;
		pthread_create(&thread, NULL, check_death, &check);
		printf("%ld %d is sleeping\n", get_current_time() - philo_data->first_eat,i);
		my_usleep(philo_data->philo_sleep);
		printf("%ld %d is thinking\n", get_current_time() - philo_data->first_eat,i);
        pthread_join(thread,NULL);
	}
}


int main(int argc,char **argv)
{
	sem_t *philo_fork;
    t_philo philo_data;
	t_const philo_const;
	pid_t *pid;


    philo_const.argc = argc;
    philo_const.argv = argv;
    if (check_arg(&philo_const) == 1)
		return (1);
	philo_const.num = ft_atoi(argv[1]);
	pid = malloc(sizeof(pid_t) * philo_const.num);
	
	arg_int_bonus(&philo_data,&philo_const);
	sem_unlink("my_forks");
	philo_fork = sem_open("my_forks", O_CREAT, 0700, philo_const.num);

	int i;
	i = 1;

	while(i <= philo_const.num)
	{
		pid[i] = fork();
		if(pid[i] == 0)
		{
			philosopher_bonus(philo_fork,&philo_data,&philo_const,i,pid[i]);
		}
		i++;
	}
	i = 1;
	while(i < philo_const.num)
	{
		waitpid(pid[i],0,0);
		i++;
	}
	kill_process(pid,&philo_const);
}
