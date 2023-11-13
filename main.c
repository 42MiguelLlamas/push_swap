#include "stack.h"

int main(int argc, char **argv)
{
    register int    i;
    t_element       *top;

	if (argc < 2)
		return (1);
    i = 0;
    while (argv[++i])
        ft_check(i, argv);
    top = NULL;
    while (--argc)
        top = t_insert(top, ft_atoi(argv[argc]));
    while (top)
    {
        ft_printf("%d\n", top->num);
        top = top->next;
    }
    return (0);
}

