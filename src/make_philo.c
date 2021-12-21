#include<philo.h>

static void *create_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	printf("N-> LLLLL\n");
	printf("ID(%ld)  Tiempo %ld\n",philo->id_thread,( get_time() - philo->info->time));
	return (NULL);
}

static void	dead(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbrs[0])
	{
		pthread_join(philo[i].id_thread, NULL);
		printf("Muerte de Thread %d: %ld\n", i, philo[i].id_thread);
		i++;
	}
}

void	make_philo(t_info *info)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = ft_calloc(info->nbrs[0], sizeof(t_philo));
	printf("INFO NBR-> %d\n", info->nbrs[0]);
	while (i < info->nbrs[0])
	{
		philo[i].info = info;
		pthread_create(&philo[i].id_thread, NULL, create_philo, &philo[i]);
		philo[i].id = i;
		i++;
	}
	dead(philo, info);
}
