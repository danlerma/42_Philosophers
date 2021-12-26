#include<philo.h>

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
