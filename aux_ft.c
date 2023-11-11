#include "stack.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	
	while (*str == ' ' || *str == '\r' || *str == '\t'
		|| *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	sign = 1;
	if (*str == '\0')
		return (0);
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10;
		num = num + (*str - '0');
		str++;
	}
	return (num * sign);
}

int	ft_isalpha(int a)
{
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
		return (1);
	return (0);
}