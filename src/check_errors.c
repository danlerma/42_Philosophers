#include<philo.h>

static int	check_numbers(char **split)
{
	int	i;
	int	y;
	int	*nbrs;

	i = -1;
	while (split[++i] != NULL)
	{
        if ((split[i][0] == 43 || split[i][0] == 45) && ft_strlen((split[i]))== 1)
            exit(0);
		if (atoi_update(split[i]) > MAX_INT || atoi_update(split[i]) < MIN_INT)
			exit(0);
	}
	nbrs = ft_calloc(i, sizeof(int));
	if (nbrs == NULL)
		return (0);
	y = -1;
	while (++y < i)
    {
		nbrs[y] = atoi_update(split[y]);    
        if(nbrs[y] < 1)
            exit(0);
    }
	free(nbrs);
	return (i);
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
int	check_errors(char **argv, int argc)
{
	char	*str;
	int		nbr;
	char	**split;

	str = union_argv(argv, argc);
	split = ft_split(str, ' ');
	if (split == NULL)
	{
		ft_free_malloc(split);
		free(str);
		return (0);
	}
	nbr = check_numbers(split);
    printf("STR-> %s\n", split[0]);
	ft_free_malloc(split);
	free(str);
	if (nbr == 0)
		return (0);
	return (nbr);
}
