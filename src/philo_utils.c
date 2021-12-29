#include<philo.h>

long	get_time(void)
{
	struct timeval	tv;
	struct timezone	tz;
	
	gettimeofday(&tv, &tz);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	first_data(t_info *info)
{
	info->n_forks = info->nbrs[0];
	info->t_die = info->nbrs[1];
	info->t_eat = info->nbrs[2];
	info->t_sleep = info ->nbrs[3];
	if (info->t_die > info->t_sleep)
		info->t_think = info->t_die - info->t_sleep;
	else
		info->t_think = 0; 
	if (info->argc == 5)
		info->must_eat = info->nbrs[4];
	else
		info->must_eat = 0;
	pthread_mutex_init(&info->print, NULL);
	info->die = 0;
	info->philos = malloc(info->n_forks + 1 * sizeof(t_philo *));
	if (info->philos == NULL)
		exit(0);
}

void	my_usleep(long time)
{
	long	now;

	now = get_time();
	while (get_time() - now <= time) ;
}

void	print_actions(t_philo *philo, int num)
{
	pthread_mutex_lock(&philo->info->print);
	if (num == 0)
		printf(YELLOW"[%ld] philo %d has taken a fork %ld\n"RESET,
			get_time() - philo->info->time, philo->id, philo->id_thread);
	else if (num == 1)
		printf(CYAN"[%ld] philo %d is eating %ld\n"RESET,
			get_time() - philo->info->time, philo->id, philo->id_thread);
	else if (num == 2)
		printf(MAGENTA"[%ld] philo %d is sleeping\n"RESET,
			get_time() - philo->info->time, philo->id);
	else if (num == 3)
		printf(GREY"[%ld] philo %d is thinking\n"RESET,
			get_time() - philo->info->time, philo->id);
	else if (num == 4)
		printf(RED"[%ld] philo %d died\n"RESET,
			get_time() - philo->info->time, philo->id);
	pthread_mutex_unlock(&philo->info->print);
}

void	show_info(t_info *info)
{
	int	i;

	i = 0;
	printf("\tINFO\n");
	printf("Argc: %d\n", info->argc);
	while (info->nbrs[i])
	{
		printf("Nbr[%d]: %d\t", i, info->nbrs[i]);
		i++;
	}
	printf("\nNum philos/forks: %d\n", info->n_forks);
	printf("Die: %d\t Eat: %d\t Sleep: %d\t Must eat: %d\n", 
		info->t_die, info->t_eat, info->t_sleep, info->must_eat);
	printf("Time: %ld\n", info->time);
}
