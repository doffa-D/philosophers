/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:28:23 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/04/04 15:55:03 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE 0
# define FALSE 1

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				*total;
	int				id;
	int				die;
	int				sleep;
	int				eat;
	int				must_eat;
	int				num;
	long			start_time;
	long			last_eat;
	int				*check;
	long			creating_time;
	pthread_mutex_t	*print;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*data_race;
}					t_philo;

long				current_time(void);

int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					check_arg(int ac, char **av);
int					check_is_digit(char **av, int ac);
int					check_rotin(t_philo *philo);
int					eating(t_philo *philo, int counter);
int					taking_fork(t_philo *philo);
int					putting_fork(t_philo *philo);
int					print(t_philo *philo, char *str, long time);
int					check_must_eat(t_philo *philo, int i);

int					sleeping(t_philo *philo);
void				*rotin(void *s);
void				free_all(pthread_t *faylasof, t_philo *philo);
void				creating_tread(pthread_t *faylasof, t_philo *philo);
void				create_fork(t_philo *philo);
void				philosopher(t_philo *philo, pthread_t *faylasof);
void				thread_join(pthread_t *faylasof, t_philo *philo);
void				my_sleep(unsigned int sleep);
void				init_mutex(t_philo *philo, pthread_mutex_t *fork);
void				init_argv(t_philo *philo, int i, char **argv, int argc);
void				initialize_arg(t_philo *philo, char **argv, int argc);

#endif