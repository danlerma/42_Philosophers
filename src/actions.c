#include<philo.h>

void	shes_dead(t_philo *philo)
{
	/*printf("HILO: %d\n", philo->id);
	printf("Time: %ld\n", get_time());
	printf("LAST EAT: %ld\n", philo->l_eat);
	printf("Resta = %ld\n", get_time() - philo->l_eat);*/
	if (philo->l_eat != 0)
	{
		if ((get_time() - philo->l_eat) > philo->info->t_die)
		{
			print_actions(philo, 4);
			philo->info->die++;
			exit(0);
		}
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
	philo->l_eat = get_time()/* - philo->info->time philo->info->t_eat*/;
	my_usleep(philo->info->t_eat);
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
