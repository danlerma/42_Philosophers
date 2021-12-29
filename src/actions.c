#include<philo.h>

void	shes_dead(t_philo *philo)
{
	long	time;

	time = get_time() - philo->info->time;
	printf("LEAT: %ld    hilo %d\n AHORA:%ld\n", philo->l_eat, philo->id, time);
	printf("Tiempo para comer: %d\n", philo->info->t_die - philo->info->t_sleep);
	printf("COMER %d: %ld\n", philo->id, time - philo->l_eat);
	if (time - philo->l_eat > philo->info->t_die - philo->info->t_sleep)
	{
		philo->info->die++;
		print_actions(philo, 4);
		exit(0);
	}
}

static void	take_fork(t_philo *philo, int pos)
{
	pthread_mutex_lock(&philo->info->philos[pos]->m_fork);
	print_actions(philo, 0);
}

void	eat(t_philo *philo)
{
	int	pos;

	pos = philo->id - 1;
	take_fork(philo, pos);
	if (pos == philo->info->n_forks - 1)
	{
		take_fork(philo, 0);
		pos = 0;
	}
	else
	{
		take_fork(philo, pos + 1);
		pos++;
	}
	print_actions(philo, 1);
	my_usleep(philo->info->t_eat);
	philo->l_eat = get_time() - philo->info->time - philo->info->t_eat;
	pthread_mutex_unlock(&philo->info->philos[pos]->m_fork);
	pthread_mutex_unlock(&philo->info->philos[philo->id - 1]->m_fork);
}

void	sleepy(t_philo *philo)
{
	print_actions(philo, 2);
	my_usleep(philo->info->t_sleep);
	print_actions(philo, 3);
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
