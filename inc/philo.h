/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:02:44 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/12/09 20:07:41 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int		*nbrs;
	int		argc;
	int		n_forks;
	int		t_eat;
	int		t_sleep;
	int		t_die;
	int		must_eat;
	long	time;
}t_info;

typedef struct s_philo
{
	pthread_t	id_thread;
	int			id;
	long		time_to_eat;
	long		time_to_sleep;
	long		time_to_die;
	t_info		*info;
}t_philo;

//check errors
void	check_errors(char **argv, int argc, t_info *info);
//make_philo
void	make_philo(t_info *info);
//philo_utils
long	get_time(void);
void	first_data(t_info *info);
void	show_info(t_info *info);
//libft
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	**ft_free_malloc(char **str);
void	ft_bzero(void *s, size_t n);
int 	ft_isdigit(int c);
long	atoi_update(const char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
