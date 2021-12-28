#include<philo.h>

 void *create_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		eat(philo);
		sleepy(philo);
	}
	return (NULL);
}

void	make_philo(t_info *info)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = malloc(info->nbrs[0] + 1 * sizeof(t_philo));
	if (philo == NULL)
		exit(0);
	info->philos = malloc(info->n_forks + 1 * sizeof(t_philo *));
	if (info->philos == NULL)
		exit(0);
	while (i < info->n_forks)
	{
		philo[i].info = info;
		philo[i].id = i + 1;
		info->philos[i] = &philo[i];
		pthread_mutex_init(&philo[i].m_fork, NULL);
		pthread_create(&philo[i].id_thread, NULL, create_philo, &philo[i]);
		i++;
	}
	dead(philo, info);
}
