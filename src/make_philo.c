#include<philo.h>

static void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_fork);
	printf(YELLOW"[%ld] philo [%d] has taken a fork\n",
		get_time() - philo->info->time, philo->id);
	printf(RESET);
	eat(philo);
	pthread_mutex_unlock(&philo->m_fork);
}

static void *create_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	pthread_mutex_init(&philo->m_fork, NULL);
	printf("ID(%ld)  Tiempo %ld\n", philo->id_thread, (get_time() - philo->info->time));
	//preguntar si puede coger el tenedor
	while (1)
	{
		take_fork(philo);
		printf(RESET);
		printf("SHGUESG_ %ld\n", get_time() - philo->info->time);
		if ((get_time() - philo->info->time) >= philo->info->t_die)
			break;
	}
	return (NULL);
}

void	make_philo(t_info *info)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = ft_calloc(info->nbrs[0], sizeof(t_philo));
	info->philo = ft_calloc(info->n_forks, sizeof(t_philo) + 1);
	printf("INFO NBR-> %d\n", info->nbrs[0]);
	while (i < info->nbrs[0])
	{
		philo[i].info = info;
		philo[i].id = i;
		info->philo[i] = philo[i];
		pthread_create(&philo[i].id_thread, NULL, create_philo, &philo[i]);
		i++;
	}
	dead(philo, info);
}
