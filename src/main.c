/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:00:30 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/12/14 15:23:57 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<philo.h>

int main(int argc, char **argv)
{
	t_info *info;

	info = ft_calloc(1, sizeof(t_info));
	if (info == NULL)
		exit(0);
	if (argc == 6)
	{
		check_errors(argv, argc, info);
		make_philo(info);
		printf("Parte con numero de veces que tienen que comer los filosofos\n");
	}
	else if (argc == 5)
	{
		check_errors(argv, argc, info);
		printf("Parte normal de los filosofos\n");
	}
	
	return (0);
}
