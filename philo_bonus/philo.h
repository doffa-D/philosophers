/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:28:23 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/04 17:45:40 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE 0
# define FALSE 1

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_philo
{
	int		total;
	int		id;
	int		die;
	int		sleep;
	int		eat;
	int		must_eat;
	int		num;
	long	start_time;
	long	last_eat;
	int		*check;
	long	creating_time;
	char	*name;
	sem_t	*print;
	sem_t	*fork;
	sem_t	*data_race;
	pid_t	pid;
}			t_philo;

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			rotine(t_philo *philo, sem_t *fork);
int			eating(t_philo *philo, sem_t *data_race);
int			sleeping(t_philo *philo);
int			putting_fork(sem_t *fork, t_philo *philo);
int			taking_fork(t_philo *philo, sem_t *fork);
int			check_is_digit(char **av, int ac);
int			check_arg(int ac, char **av);
void		kill_process_b(t_philo *philo);
int			print(t_philo *philo, char *str, long time);
void		*check_rotin(void *arg);
int			philosopher(t_philo *philo);
void		initialize_arg(t_philo *philo, char **argv, int argc);
void		my_sleep(unsigned int sleep);
long		current_time(void);
char		*ft_itoa(int n);

#endif