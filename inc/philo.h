/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:02:44 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/01/03 19:46:51 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define RED "\033[1;31m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;90m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"
# define RESET "\033[0m"

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_info
{
	int				*nbrs;
	int				argc;
	int				n_forks;
	int				t_eat;
	int				t_sleep;
	int				t_die;
	int				die;
	int				must_eat;
	long			time;
	pthread_mutex_t	print;
	struct s_philo	**philos;
}t_info;

typedef struct s_philo
{
	pthread_t		id_thread;
	pthread_mutex_t	m_fork;
	int				id;
	int				num_eat;
	long			l_eat;
	int				cnt;
	t_info			*info;
}t_philo;

//check errors
void	check_errors(char **argv, int argc, t_info *info);
//make_philo
void	make_philo(t_info *info);
//philo_utils
long	get_time(void);
void	first_data(t_info *info);
void	print_actions(t_philo *philo, int num);
void	my_usleep(long time);
//actions
void	eat(t_philo *philo);
void	sleepy(t_philo *philo);
void	shes_dead(t_philo *philo);
//libft
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);
char	**ft_split(char const *s, char c);
char	**ft_free_malloc(char **str);
long	atoi_update(const char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
