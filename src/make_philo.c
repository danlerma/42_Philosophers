#include<philo.h>

static void *create_philo(void *num)
{
	int i;
	int n = *((int *)num);

	i = 0;
	while (i < n)
	{
		printf("Soy el hilo %d\n", i);
		i++;
	}
	return (NULL);
}

void	make_philo(t_info *info)
{
	int			i;
	pthread_t	philo;

	i = 0;
	while (i < info->nbrs[1])
	{
		pthread_create(&philo, NULL, create_philo, &i);
		pthread_join(philo, NULL);
		printf("THREAAD %d: %ld\n", i, philo);
		i++;
	}
}
