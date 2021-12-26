#include<philo.h>
static	void	take_fork(t_philo *philo, int num)
{
	pthread_mutex_lock(&philo[num].m_fork);
	printf(YELLOW"[%ld]philo %d has taken a fork\n",
		get_time() - philo->info->time, philo->id);
}

void	eat(t_philo *philo)
{
	int	id;

	id = philo->id;
	take_fork(philo, id);
	if (id == philo->info->n_forks - 1)
		take_fork(philo, 0);
	else
		take_fork(philo, id + 1);
	printf(CYAN"[%ld] philo %d is eating\n",
		get_time() - philo->info->time, philo->id);
	pthread_mutex_unlock(&philo[philo->id].m_fork);
	pthread_mutex_unlock(&philo[id].m_fork);
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
