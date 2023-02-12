/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:54:41 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/12 22:31:22 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

long get_current_time11()
{

    struct timeval start;
     gettimeofday(&start, NULL);
  return (start.tv_sec ) * 1000 + (start.tv_usec ) / 1000;
}

void *philosopher(void *ptr)
{
    t_philo *philo = (t_philo *)ptr;
    int eating_count = 0;
    if(philo->id % 2 == 0)
    {
        usleep(30);
    }
    while (1)
    {
        pthread_mutex_lock(philo->left_fork);
        pthread_mutex_lock(philo->right_fork);
        printf("%ld %d has taken a fork\n",get_current_time11()-philo->first_eat, philo->id);
        printf("%ld %d is eating\n",get_current_time11()-philo->first_eat, philo->id);
        philo->last_eat = get_current_time11();
        eating_count++;
        usleep(philo->philo_eat);
        if(eating_count >= philo->philo_must_eat)
        {
            break;
        }
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        printf("%ld %d is sleeping\n",get_current_time11()-philo->first_eat, philo->id);
        usleep(philo->philo_sleep);
        printf("%ld %d is thinking\n",get_current_time11()-philo->first_eat,philo->id);
    }
    return NULL;
}

int main(int argc,char **argv)
{
    int i;
    (void)argc;
    t_philo *philo_data;
    pthread_t *philo;
    pthread_mutex_t *fork;
    int philo_num;
    long start_time = get_current_time11();
    i = 0;
    philo_num = ft_atoi(argv[1]);
    philo_data = malloc(sizeof(t_philo) * philo_num);
    philo = malloc(sizeof(pthread_t) * philo_num);
    fork = malloc(sizeof(pthread_mutex_t)*philo_num);

    while(i < philo_num)
    {
        pthread_mutex_init(&fork[i],NULL);
        i++;
    }
    i = 0;
    while(i < philo_num)
    {
        philo_data[i].id = i;
        philo_data[i].first_eat = start_time;
        philo_data[i].last_eat = start_time;
        philo_data[i].philo_die = ft_atoi(argv[2]);
        philo_data[i].philo_eat = ft_atoi(argv[3])*1000;
        philo_data[i].philo_sleep = ft_atoi(argv[4])*1000;
        philo_data[i].philo_must_eat = ft_atoi(argv[5]);
        philo_data[i].left_fork = &fork[i];
        philo_data[i].right_fork = &fork[(i + 1) % philo_num];
        i++;
    }
    i = 0;
    while(i < philo_num)
    {
        pthread_create(&philo[i],NULL,philosopher,&philo_data[i]);
            i++;
    }
    i = 0;
    while(i < philo_num)
    {
        pthread_join(philo[i],0);
        i++;
    }
    i = 0;
    while(i < philo_num)
    {
        pthread_mutex_destroy(&fork[i]);
        i++;
    }

    return 0;
}