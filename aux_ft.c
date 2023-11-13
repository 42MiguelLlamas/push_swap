#include "stack.h"
#include <string.h>

int	ft_atoi(char *argv)
{
	int	sign;
	long int	num;

	sign = 1;
	if (*argv == '-')
	{
		sign = -sign;
		argv++;
	}
	else if (*argv == '+')
		argv++;
	num = 0;
	while (*argv >= '0' && *argv <= '9')
	{
		num = num * 10;
		num = num + (*argv - '0');
		argv++;
	}
	if ((num*sign) < -2147483648 || (num*sign) > 2147483647)
	{
		write(2, "Error, no es int\n", 17);
		exit(1);
	}
	return (num * sign);
}

void ft_check(const int index, char **argv)
{
	register int	j;

	ft_printf("%s\n", argv[index]);
	if (*argv[index] == '-' || *argv[index] == '+')
		argv[index]++;
	while (*argv[index])
	{
		if (*argv[index] >= '0' && *argv[index] <= '9')
			argv[index]++;
		else
		{
			write(2, "Error, argvumento no entero\n", 28);
			exit(1);
		}
	}
	j = 0;
	while (argv[++j])
	{
		ft_printf("%d %d\n", index, j);
		if (ft_atoi(argv[index]) == ft_atoi(argv[j]) && j != index)
		{
			ft_printf("%s %s\n", argv[index], argv[j]);
			ft_printf("%d %d\n", ft_atoi(argv[index]), ft_atoi(argv[j]));
			write(2, "Error, argvumento repetido\n", 27);
			exit(1);
		}				
	}
	ft_printf("%s\n", "ok repetido");
}
