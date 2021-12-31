#include<philo.h>

void	shes_dead(t_philo *philo)
{
	if (philo->l_eat != 0)
	{
		if ((get_time() - philo->l_eat) > philo->info->t_die)
		{
			print_actions(philo, 4);
			pthread_mutex_lock(&philo->info->print);
			exit(0);
		}
	}
	if (philo->info->n_forks == 1)
	{
		print_actions(philo, 0);
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
	shes_dead(philo);
	print_actions(philo, 1);
	philo->l_eat = get_time();
	my_usleep(philo->info->t_eat);
	philo->cnt++;
	pthread_mutex_unlock(&philo->info->philos[pos]->m_fork);
	pthread_mutex_unlock(&philo->info->philos[philo->id - 1]->m_fork);
}

void	sleepy(t_philo *philo)
{
	print_actions(philo, 2);
	my_usleep(philo->info->t_sleep);
	shes_dead(philo);
	print_actions(philo, 3);
}
