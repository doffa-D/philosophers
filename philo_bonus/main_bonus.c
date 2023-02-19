/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:44:33 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/19 12:38:40 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *data)
{
	t_check	*philo_data;
	long	new;

	philo_data = (t_check *)data;
	while (1)
	{
		new = get_current_time();
		if (new - philo_data->last_eat >= philo_data->philo_die)
		{
			printf("%ld %d died\n", get_current_time() - philo_data->first_eat,
				philo_data->id);
			kill_process_b(philo_data->pid, philo_data->num, philo_data->fork);
		}
		usleep(10);
	}
	return (NULL);
}

void	process(sem_t *philo_fork, t_philo *philo_data, t_check *check)
{
	sem_wait(philo_fork);
	printf("%ld %d has taken a fork\n", get_current_time()
		- philo_data->first_eat, check->id);
	sem_wait(philo_fork);
	printf("%ld %d has taken a fork\n", get_current_time()
		- philo_data->first_eat, check->id);
	printf("%ld %d is eating\n", get_current_time() - philo_data->first_eat,
		check->id);
	check->last_eat = get_current_time();
	check->eating_count++;
	my_usleep(philo_data->philo_eat);
	if (check->eating_count >= philo_data->philo_must_eat)
		kill_process_b(check->pid, check->num, philo_fork);
	sem_post(philo_fork);
	sem_post(philo_fork);
	printf("%ld %d is sleeping\n", get_current_time() - philo_data->first_eat,
		check->id);
	my_usleep(philo_data->philo_sleep);
	printf("%ld %d is thinking\n", get_current_time() - philo_data->first_eat,
		check->id);
}

void	philosopher_bonus(sem_t *philo_fork, t_philo *philo_data, t_check check)
{
	pthread_t	thread;

	check.first_eat = philo_data->first_eat;
	check.fork = philo_fork;
	check.last_eat = get_current_time();
	check.eating_count = 0;
	if (pthread_create(&thread, NULL, check_death, &check) != 0)
	{
		printf("Pthread_create field\n");
		free(&check);
		exit(1);
	}
	while (1)
		process(philo_fork, philo_data, &check);
	pthread_join(thread, NULL);
}

void	life(sem_t *philo_fork, t_check *check, pid_t *pid, t_philo philo_data)
{
	int	i;

	i = 1;
	sem_unlink("/my_forks");
	philo_fork = sem_open("/my_forks", O_CREAT, 0700, check->num);
	while (i <= check->num)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			check[i].pid = pid;
			check[i].id = i;
			check[i].philo_die = philo_data.philo_die;
			check[i].num = check->num;
			philosopher_bonus(philo_fork, &philo_data, check[i]);
		}
		i++;
	}
	i = 1;
	while (i <= check->num)
	{
		waitpid(pid[i], 0, 0);
		i++;
	}
	kill_process_b(pid, check->num, philo_fork);
}

int	main(int argc, char **argv)
{
	sem_t	philo_fork;
	t_philo	philo_data;
	t_const	philo_const;
	pid_t	*pid;
	t_check	*check;

	philo_const.argc = argc;
	philo_const.argv = argv;
	if (check_arg(&philo_const) == 1)
		return (1);
	pid = malloc(sizeof(pid_t) * philo_const.num);
	check = malloc(sizeof(t_check) * philo_const.num);
	if (!pid || !check)
		return (1);
	arg_int_bonus(&philo_data, &philo_const);
	check->num = ft_atoi(argv[1]);
	life(&philo_fork, check, pid, philo_data);
	free(pid);
	free(check);
}
