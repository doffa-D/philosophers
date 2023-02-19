/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:55:17 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/19 13:29:21 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_const
{
	int				num;
	int				argc;
	char			**argv;
	long			start_time;
}					t_const;

typedef struct s_philo
{
	int				id;
	int				philo_die;
	int				philo_eat;
	int				philo_sleep;
	int				philo_must_eat;
	int				philo_total_eat;
	long			first_eat;
	long			last_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

long				get_current_time(void);

int					check(t_philo *philo_data, t_const *philo_const,
						pthread_t *philo);
int					is_int(char **argv);
int					check_arg(t_const *philo_const);
int					quick_check(t_philo *philo_data, int num,
						pthread_mutex_t *protect_philo);
void				arg_int(t_philo *philo_data, t_const *philo_const,
						pthread_mutex_t *fork);
void				exit_error(void);
void				free_param(t_philo *philo_data, pthread_t *philo,
						pthread_mutex_t *fork);
void				my_usleep(unsigned int usec);
void				destroy_mu(t_philo *philo_data, int num);
void				pthread(t_philo *philo);
void				*philosopher(void *ptr);
void				destroy_mu(t_philo *philo_data, int num);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);

#endif