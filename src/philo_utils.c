/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:25:23 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/05 16:49:12 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<philo.h>

long	get_time(void)
{
	struct timeval	tv;
	struct timezone	tz;

	gettimeofday(&tv, &tz);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	first_data(t_info *info)
{
	info->n_forks = info->nbrs[0];
	info->t_die = info->nbrs[1];
	info->t_eat = info->nbrs[2];
	info->t_sleep = info ->nbrs[3];
	if (info->argc == 5)
		info->must_eat = info->nbrs[4];
	else
		info->must_eat = -1;
	pthread_mutex_init(&info->print, NULL);
	info->die = 0;
	info->philos = malloc(info->n_forks + 1 * sizeof(t_philo *));
	if (info->philos == NULL)
		exit(0);
	info->time = get_time();
}

void	my_usleep(long time)
{
	long	now;

	now = get_time();
	while (get_time() - now < time)
		;
}

void	print_actions(t_philo *philo, int num)
{
	pthread_mutex_lock(&philo->info->print);
	if (num == 0 && philo->info->die == 0)
		printf(YELLOW"[%ld] philo %d has taken a fork\n"RESET,
			get_time() - philo->info->time, philo->id);
	else if (num == 1 && philo->info->die == 0)
		printf(CYAN"[%ld] philo %d is eating\n"RESET,
			get_time() - philo->info->time, philo->id);
	else if (num == 2 && philo->info->die == 0)
		printf(MAGENTA"[%ld] philo %d is sleeping\n"RESET,
			get_time() - philo->info->time, philo->id);
	else if (num == 3 && philo->info->die == 0)
		printf(GREY"[%ld] philo %d is thinking\n"RESET,
			get_time() - philo->info->time, philo->id);
	else if (num == 4 && philo->info->die == 0)
		printf(RED"[%ld] philo %d died\n"RESET,
			get_time() - philo->info->time, philo->id);
	pthread_mutex_unlock(&philo->info->print);
}
