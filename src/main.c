/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:00:30 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/06 14:09:21 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<philo.h>

int	main(int argc, char **argv)
{
	t_info	*info;

	info = malloc(1 * sizeof(t_info));
	if (info == NULL)
		return (0);
	if (argc == 6 || argc == 5)
	{
		if (check_errors(argv, argc, info) == 1)
			return (0);
		if (first_data(info) == 1)
			return (0);
		make_philo(info);
	}
	return (0);
}
