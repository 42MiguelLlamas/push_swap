#include "stack.h"

int main(int argc, char **argv)
{
    register int    i;

	if (argc == 1 && argv[0])
    {
        ft_printf("%s\n", "Inserte argumentos, por favor.");
		return (1);
    }
    i = 1;
    while (argv[++i])
        ft_check(argv[i]);
    
    return (0);
}