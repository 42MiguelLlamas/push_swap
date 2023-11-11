#include "stack.h"

int main(int argc, char **argv)
{
    ft_printf("%d\n", argc);

	if (argc == 1 && argv[0])
    {
        ft_printf("%s\n", "Inserte argumentos, por favor.");
		return (1);
    }
    while (*argv)
    {
        ft_printf("%s\n", *argv);
        argv++;
    }
    return (0);
}