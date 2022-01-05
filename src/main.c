/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:00:30 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/05 19:46:19 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<philo.h>

void leaks()
{
	system("leaks -q philo");
}

int	main(int argc, char **argv)
{
	t_info	*info;

	//atexit(leaks);
	info = malloc(1 * sizeof(t_info));
	if (info == NULL)
		return (0);
	if (argc == 6 || argc == 5)
	{
		if (check_errors(argv, argc, info) == 1)
			return (0);
		//system("leaks -q philo");
		if (first_data(info) == 1)
			return (0);
		make_philo(info);
	}
	free(info);
	return (0);
}
