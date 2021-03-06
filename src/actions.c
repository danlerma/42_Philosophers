/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:12:20 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/06 17:00:47 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<philo.h>

int	shes_dead(t_philo *philo)
{
	if (philo->info->die == 1)
		return (1);
	if (philo->l_eat != 0)
	{
		if ((get_time() - philo->l_eat) > philo->info->t_die)
		{
			print_actions(philo, 4);
			philo->info->die++;
			unlock(philo);
			return (1);
		}
	}
	if (philo->info->n_forks == 1)
	{
		print_actions(philo, 0);
		my_usleep(philo->info->t_eat);
		print_actions(philo, 4);
		return (1);
	}
	return (0);
}

static void	take_fork(t_philo *philo, int pos)
{
	pthread_mutex_lock(&philo->info->philos[0][pos].m_fork);
	print_actions(philo, 0);
}

void	eat(t_philo *philo)
{
	int	pos;

	pos = philo->id - 1;
	take_fork(philo, pos);
	if (pos == philo->info->n_forks - 1)
	{
		take_fork(philo, 0);
		pos = 0;
	}
	else
	{
		take_fork(philo, pos + 1);
		pos++;
	}
	if (shes_dead(philo) == 1)
		return ;
	print_actions(philo, 1);
	philo->l_eat = get_time();
	philo->cnt++;
	my_usleep(philo->info->t_eat);
	pthread_mutex_unlock(&philo->info->philos[0][pos].m_fork);
	pthread_mutex_unlock(&philo->m_fork);
}

void	sleepy(t_philo *philo)
{
	print_actions(philo, 2);
	my_usleep(philo->info->t_sleep);
}
