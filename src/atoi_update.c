#include<philo.h>

static int	check_space_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == 45)
		*sign = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	return (i);
}

static long	check_alpha(const char *str, int pos, long result)
{
	int	num;

	while (str[pos])
	{
		num = ft_isdigit(str[pos]);
		if (num == 0)
			return ((long)MAX_INT + 2);
		pos++;
	}
	return (result);
}

long	atoi_update(const char *str)
{
	int			i;
	long long	result;
	int			sign;

	i = 0;
	sign = 1;
	result = 0;
	i = check_space_sign(str, &sign);
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (result * sign > 2147483647)
			return ((long)MAX_INT + 1);
		else if (result * sign < -2147483648)
			return (MIN_INT - 1);
		else
			result = result * 10 + str[i] - '0';
		i++;
	}
	result = check_alpha(str, i, result);
	return (result * sign);
}
