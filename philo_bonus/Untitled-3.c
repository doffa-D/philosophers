
long	get_current_time(void)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return ((start.tv_sec) * 1000 + (start.tv_usec) / 1000);
}


void	philosopher_bonus(sem_t *philo_fork,t_philo *philo_data,t_const *philo_const)
{

	int eating_count;
	eating_count = 0;
	(void)philo_const;
	while(1)
	{
		sem_wait(philo_fork);
		printf("%ld %d has taken a fork\n", get_current_time() - philo_data->first_eat,philo_data->id);
		sem_wait(philo_fork);
		printf("%ld %d has taken a fork\n", get_current_time() - philo_data->first_eat,philo_data->id);
		printf("%ld %d is eating\n", get_current_time() - philo_data->first_eat,philo_data->id);
		my_usleep(philo_data->philo_eat);
		sem_post(philo_fork);
		sem_post(philo_fork);
		printf("%ld %d is sleeping\n", get_current_time() - philo_data->first_eat,philo_data->id);
		my_usleep(philo_data->philo_sleep);
		printf("%ld %d is thinking\n", get_current_time() - philo_data->first_eat,philo_data->id);
	}

}


int main(int argc,char **argv)
{
	sem_t *philo_fork;
    t_philo *philo_data;
	t_const philo_const;
	pid_t *pid;
	int i;

    philo_const.argc = argc;
    philo_const.argv = argv;
    if (check_arg(&philo_const) == 1)
		return (1);
	philo_const.num = ft_atoi(argv[1]);
	pid = malloc(sizeof(pid_t) * philo_const.num);
	philo_fork = malloc(sizeof(sem_t) * philo_const.num);
	philo_data = malloc(sizeof(t_philo) * philo_const.num);
	// arg_int_bonus(&philo_data,&philo_const);
	sem_unlink("my_forks");
	i = 0;
	while(i < philo_const.num)
	{
		philo_fork[i] = sem_open("my_forks", O_CREAT, 0700, 1);
		if(philo_fork[i] == SEM_FAILED)
		{
			sem_close(philo_fork);
			sem_unlink("my_forks");
		}
		i++;
	}

	i = 0;
	while(i < philo_const.num)
	{
		pid[i] = fork();
		if(pid[i] == 0)
		{
			philo_data[i].id = i;
			philo_data[i].first_eat = get_current_time();
			philo_data[i].last_eat = get_current_time();
			philo_data[i].philo_die = ft_atoi(philo_const.argv[2]);
			philo_data[i].philo_eat = ft_atoi(philo_const.argv[3]);
			philo_data[i].philo_sleep = ft_atoi(philo_const.argv[4]);
			if (philo_const.argc == 6)
				philo_data[i].philo_must_eat = ft_atoi(philo_const.argv[5]);
			else
				philo_data[i].philo_must_eat = INT_MAX;
			philosopher_bonus(&philo_fork[i],&philo_data[i],&philo_const);
		}
		i++;
	}
}
