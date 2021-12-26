#include<philo.h>
static	void	take_fork(t_philo *philo, int num)
{
	printf("FORK ID: %d %ld\n", num, philo->id_thread);
	pthread_mutex_lock(&philo->info->philo[num].m_fork);
	printf(YELLOW"[%ld] philo %d has taken a fork %ld\n"RESET,
		get_time() - philo->info->time, philo->id, philo->id_thread);
}

void	eat(t_philo *philo)
{
	int	id;

	id = philo->id;
	take_fork(philo, id);
	if (id == philo->info->n_forks - 1)
	{
		take_fork(philo, 0);
		pthread_mutex_unlock(&philo->info->philo[0].m_fork);
		printf(CYAN"[%ld] philo %d is eating %ld\n"RESET,
			get_time() - philo->info->time, philo->id, philo->id_thread);
	}
	else
	{
		take_fork(philo, id + 1);
		printf(CYAN"[%ld] philo %d is eating %ld\n"RESET,
			get_time() - philo->info->time, philo->id, philo->id_thread);
		pthread_mutex_unlock(&philo->info->philo[id + 1].m_fork);
	}
	pthread_mutex_unlock(&philo->info->philo[philo->id].m_fork);
}

void	sleep(t_philo *philo)
{
	printf(MAGENTA"[%ld] philo %d is sleeping %ld\n"RESET,
		get_time() - philo->info->time, philo->id, philo->id_thread);
	my_usleep(philo->info->t_sleep);
}

void	dead(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbrs[0])
	{
		pthread_join(philo[i].id_thread, NULL);
		printf(RED"[%ld] philo %d died\n",
			get_time() - philo->info->time, philo->id);
		i++;
	}
	exit(0);
}
