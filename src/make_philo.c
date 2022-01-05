/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:21:13 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/05 16:44:03 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	*create_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *) p;
	if (philo->id % 2 != 0)
		usleep(100);
	while (1)
	{
		if (philo->cnt == philo->info->must_eat)
			break ;
		shes_dead(philo);
		eat(philo);
		shes_dead(philo);
		sleepy(philo);
	}
	return (NULL);
}

/*static char	*ft_strdup(const char *s1)
{
	char	*str;
	int		num;

	num = ft_strlen((char *)s1);
	str = malloc(num + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, num * sizeof(char) + 1);
	str[num] = '\0';
	return (str);
}*/

void	make_philo(t_info *info)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = malloc(info->nbrs[0] * sizeof(t_philo));
	if (philo == NULL)
		exit(0);
	info->philos = &philo;
	while (i < info->n_forks)
	{
		philo[i].info = info;
		philo[i].id = i + 1;
		philo[i].l_eat = 0;
		philo[i].cnt = 0;
		info->philos[0][i] = philo[i];
		printf("PRUEBA: %d\n", info->philos[0][i].id);
		pthread_mutex_init(&philo[i].m_fork, NULL);
		pthread_create(&philo[i].id_thread, NULL, create_philo, &philo[i]);
		i++;
	}
	dead(philo, info);
}
