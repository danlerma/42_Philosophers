#include<philo.h>

static void *create_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	if (philo->id != 0)
		my_usleep(100);
	while (1)
	{
		printf("HIOLQ\n");
		eat(philo);
	}
	return (NULL);
}

void	make_philo(t_info *info)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = ft_calloc(info->nbrs[0] + 1, sizeof(t_philo));
	info->philo = ft_calloc(info->n_forks + 1, sizeof(t_philo));
	while (i < info->nbrs[0])
	{
		philo[i].info = info;
		philo[i].id = i;
		info->philo[i] = philo[i];
		pthread_mutex_init(&philo[i].m_fork, NULL);
		pthread_create(&philo[i].id_thread, NULL, create_philo, &philo[i]);
		i++;
	}
	//dead(philo, info);
}
