/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:54:41 by hdagdagu          #+#    #+#             */
/*   Updated: 2023/02/16 12:52:52 by hdagdagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"
long get_current_time11()
{
    struct timeval start;
     gettimeofday(&start, NULL);
  return (start.tv_sec ) * 1000 + (start.tv_usec ) / 1000;
}

// #include <sys/time.h>
// #include <unistd.h>

// long get_current_time11() {
//     struct timeval start;
//     gettimeofday(&start, NULL);
//     return (start.tv_sec) * 1000 + (start.tv_usec) / 1000;
// }

void my_usleep(unsigned int usec)
{
    long start_time;
    long current_time;
    long time;

    start_time = get_current_time11();
    time = 0;
    while (time < usec)
    {
        current_time = get_current_time11();
        time = current_time - start_time;
    usleep(100);
    }
}



void *philosopher(void *ptr)
{
    t_philo *philo = (t_philo *)ptr;
    int eating_count = 0;
    if(philo->id % 2 == 1)
    {
        usleep(30);
    }
    if(philo->force == 1)
        exit(0);
    while (1)
    {
        pthread_mutex_lock(philo->left_fork);
        printf("%ld %d has taken a fork\n",get_current_time11()-philo->first_eat, philo->id);
        pthread_mutex_lock(philo->right_fork);
        printf("%ld %d has taken a fork\n",get_current_time11()-philo->first_eat, philo->id);
        printf("%ld %d is eating\n",get_current_time11()-philo->first_eat, philo->id);
        philo->last_eat = get_current_time11();
        eating_count++;
        my_usleep(philo->philo_eat);
        if(eating_count >= philo->philo_must_eat)
            philo->philo_total_eat++;
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        printf("%ld %d is sleeping\n",get_current_time11()-philo->first_eat, philo->id);
        my_usleep(philo->philo_sleep);
        printf("%ld %d is thinking\n",get_current_time11()-philo->first_eat,philo->id);
    }
    return NULL;
}
void    quick_check(t_philo *philo_data,int num)
{
    int i;
    i = 0;
    while(1)
    {
        // if(philo_data[i].philo_total_eat == num)
        // {
        //     while(i < num)
        //         pthread_mutex_destroy(&philo_data->left_fork[i++]);
        //     // printf("ssss\n");
        //     exit(0);
        // }
        if (get_current_time11() - philo_data[i].last_eat >= philo_data->philo_die)
        {
            pthread_mutex_unlock(philo_data[i].left_fork);
            pthread_mutex_unlock(philo_data[i].right_fork);
            philo_data[i].force = 1;
            printf("%ld %d died\n",get_current_time11()-philo_data[i].first_eat, philo_data->id);
            exit(0);
        }
        i = (i + 1) % num;
		usleep(500);
    }
    return ;
}
int main(int argc,char **argv)
{
    int i;
    printf("%d\n",argc);
    t_philo *philo_data;
    pthread_t *philo;
    pthread_mutex_t *fork;
    int num = ft_atoi(argv[1]);
    long start_time = get_current_time11();
    i = 0;
    philo_data = malloc(sizeof(t_philo) * num);
    philo = malloc(sizeof(pthread_t) * num);
    fork = malloc(sizeof(pthread_mutex_t)*num);

    while(i < num)
    {
        pthread_mutex_init(&fork[i],NULL);
        i++;
    }
    i = 0;
    while(i < num)
    {
        philo_data[i].id = i;
        philo_data[i].first_eat = start_time;
        philo_data[i].last_eat = start_time;
        philo_data[i].philo_die = ft_atoi(argv[2]);
        philo_data[i].philo_eat = ft_atoi(argv[3]);
        philo_data[i].philo_sleep = ft_atoi(argv[4]);
        philo_data[i].force = 0;
        if(argc == 6)
            philo_data[i].philo_must_eat = ft_atoi(argv[5]);
        philo_data[i].left_fork = &fork[i];
        philo_data[i].right_fork = &fork[(i + 1) % num];
        i++;
    }
    i = 0;
    while(i < num)
    {
        pthread_create(&philo[i],NULL,philosopher,&philo_data[i]);
            i++;
    }
    quick_check(philo_data,num);
    i = 0;
    while(i < num)
    {
        pthread_join(philo[i],NULL);
        i++;
    }
    return 0;
}