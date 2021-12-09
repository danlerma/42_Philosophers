/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:00:30 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/12/09 20:24:54 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<philo.h>

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 6)
	{
		printf("Parte con numero de veces que tienen que comer los filosofos\n");
	}
	else if (argc == 5)
	{
		printf("Parte normal de los filosofos\n");
	}
	return (0);
}
