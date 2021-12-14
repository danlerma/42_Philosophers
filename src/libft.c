#include<philo.h>

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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*str;
	const char	*s;

	i = -1;
	str = dst;
	s = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (++i < n)
		str[i] = s[i];
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		num;

	num = ft_strlen((char *)s1);
	str = malloc(num + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, num * sizeof(char) + 1);
	str[num] = '\0';
	return (str);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int		i;
	char				*str;

	i = -1;
	str = (char *) s;
	while (++i < n)
		str[i] = 0;
}

char	**ft_free_malloc(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**error_malloc(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	count_sep(const char *s, char c, char type)
{
	int	i;

	i = 0;
	if (type == 'p')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	else
	{
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (i);
}

static int	count_rows(const char *s, char c)
{
	unsigned int	i;
	int				cnt;

	i = 0;
	cnt = 0;
	if (s[0] && s[0] != c)
		cnt = 1;
	while (i < ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			cnt++;
		i++;
	}
	return (cnt);
}

static char	**assing_str(char **str, const char *s, char c, int numrows)
{
	int	i;
	int	ncolumn;
	int	numchar;
	int	aux;

	i = 0;
	aux = count_sep(s, c, 'p');
	ncolumn = count_sep(&s[aux], c, 's');
	while (i < numrows)
	{
		str[i] = malloc((ncolumn + 1) * sizeof(char));
		if (str[i] == NULL)
			return (error_malloc(str));
		ft_strlcpy(str[i], &s[aux], ncolumn + 1);
		aux = aux + ncolumn;
		numchar = count_sep(&s[aux], c, 'p');
		aux = numchar + aux;
		ncolumn = count_sep(&s[aux], c, 's');
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		nrows;
	char	**str;

	if (s == NULL)
		return (NULL);
	nrows = count_rows(s, c);
	str = ft_calloc(sizeof(char *), (nrows + 1));
	if (str == NULL)
		return (NULL);
	str = assing_str(str, s, c, nrows);
	return (str);
}
