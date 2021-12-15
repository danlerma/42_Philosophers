/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:59:44 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/12/14 15:28:18 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<philo.h>

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(size + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	size = 0;
	while (s2[size])
	{
		str[i] = s2[size];
		i++;
		size++;
	}
	str[i] = '\0';
	return (str);
}

static void	check_numbers(char **split, t_info *info)
{
	int	i;
	int	y;

	i = -1;
	while (split[++i] != NULL)
	{
		if ((split[i][0] == 43 || split[i][0] == 45) &&
			ft_strlen(split[i]) == 1)
			exit(0);
		if (atoi_update(split[i]) > MAX_INT || atoi_update(split[i]) < MIN_INT)
			exit(0);
	}
	info->nbrs = ft_calloc(i, sizeof(int));
	if (info->nbrs == NULL)
		exit(0);
	y = -1;
	while (++y < i)
	{
		info->nbrs[y] = atoi_update(split[y]);
		if (info->nbrs[y] < 1)
			exit(0);
	}
}

static char	*union_argv(char **argv, int argc)
{
	char	*aux;
	int		i;
	char	*str;

	str = ft_strdup(argv[1]);
	i = 2;
	while (i < argc)
	{
		aux = str;
		str = ft_strjoin(aux, " ");
		free(aux);
		aux = str;
		str = ft_strjoin(aux, argv[i]);
		free(aux);
		i++;
	}
	return (str);
}

void	check_errors(char **argv, int argc, t_info *info)
{
	char	*str;
	char	**split;

	str = union_argv(argv, argc);
	split = ft_split(str, ' ');
	if (split == NULL)
	{
		ft_free_malloc(split);
		free(str);
		exit(0);
	}
	info->num = argc - 2;
	check_numbers(split, info);
	ft_free_malloc(split);
	free(str);
}
