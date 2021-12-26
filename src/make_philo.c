#include<philo.h>

 void *create_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
/*	if (philo->id != 0)
	{
		my_usleep(100);
	}*/
		printf("ID-> %d    %ld\n", philo->id, philo->id_thread);
	while (1)
	{
		//eat(philo);
		//sleep(philo);
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
	info->philo = malloc(info->n_forks + 1 * sizeof(t_philo *));
	if (info->philo == NULL)
		exit(0);
	while (i < info->n_forks)
	{
		philo[i].info = info;
		philo[i].id = i;
		philo[i].prueba = 100;
		printf("PRUEBA DESDE PHILO %d = %d\n", philo[i].id, philo[i].prueba);
		info->philo[i] = &philo[i];
		philo->info->philo[i]->prueba = 300;
		printf("PRUEBA DESDE INFO  %d = %d\n", philo[i].id, philo[i].prueba);
		pthread_mutex_init(&philo[i].m_fork, NULL);
		//pthread_create(&philo[i].id_thread, NULL, create_philo, &philo[i]);
		i++;
	}
	//dead(philo, info);
}
