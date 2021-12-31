#include<philo.h>

static void	dead(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbrs[0])
	{
		pthread_join(philo[i].id_thread, NULL);
		i++;
	}
	exit(0);
}

 void *create_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	if (philo->id % 2 == 0)
		usleep(10000);
	while (1)
	{
		if (philo->cnt == philo->info->must_eat)
			break ;
		shes_dead(philo);
		eat(philo);
		shes_dead(philo);
		sleepy(philo);
		shes_dead(philo);
	}
	return (NULL);
}

void	make_philo(t_info *info)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = malloc(info->nbrs[0] * sizeof(t_philo));
	if (philo == NULL)
		exit(0);
	while (i < info->n_forks)
	{
		philo[i].info = info;
		philo[i].id = i + 1;
		philo[i].l_eat = 0;
		philo[i].cnt = 0; 
		info->philos[i] = &philo[i];
		pthread_mutex_init(&philo[i].m_fork, NULL);
		pthread_create(&philo[i].id_thread, NULL, create_philo, &philo[i]);
		i++;
	}
	dead(philo, info);
}
