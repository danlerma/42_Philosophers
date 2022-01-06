/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:21:13 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/06 14:08:05 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<philo.h>

static void	dead(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_forks)
	{
		pthread_join(philo[i].id_thread, NULL);
		i++;
	}
}

void	*create_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	if (philo->id % 2 == 0)
		my_usleep(100);
	while (1)
	{
		if (philo->cnt == philo->info->must_eat)
			break ;
		if (shes_dead(philo) == 1)
			break ;
		eat(philo);
		if (shes_dead(philo) == 1)
			break ;
		sleepy(philo);
		if (shes_dead(philo) == 1)
			break ;
		print_actions(philo, 3);
	}
	return (NULL);
}

int	make_philo(t_info *info)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = NULL;
	philo = malloc(info->n_forks + 1 * sizeof(t_philo));
	if (philo == NULL)
		return (0);
	info->philos[info->n_forks] = NULL;
	free(info->philos);
	info->philos = &philo;
	while (i < info->n_forks)
	{
		philo[i].info = info;
		philo[i].id = i + 1;
		philo[i].l_eat = 0;
		philo[i].cnt = 0;
		info->philos[0][i] = philo[i];
		pthread_mutex_init(&philo[i].m_fork, NULL);
		pthread_create(&philo[i].id_thread, NULL, create_philo, &philo[i]);
		i++;
	}
	dead(philo, info);
	free(philo);
	return (0);
}
