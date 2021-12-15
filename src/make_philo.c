#include<philo.h>

static void *create_philo(void *num)
{
	int n = *((int *)num);

	printf("N-> %d\n", n);
		printf("Soy el hilo %d\n", n);
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
		pthread_create(&philo[i].id_thread, NULL, create_philo, &i);
		philo[i].id = i;
		i++;
	}
	dead(philo, info);
}
