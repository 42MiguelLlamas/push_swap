#include "stack.h"

t_element   *t_insert(t_element *top, int number)
{
    t_element   *temp;
    temp = malloc(sizeof(t_element *));
    if (!temp)
        return (NULL);
    temp->num = number;
    temp->next = top;
    top = temp;
    return (top);
}

int main(int argc, char **argv)
{
    register int    i;
    t_element       *top;

	if (argc < 2)
    {
        ft_printf("%s\n", "Inserte argumentos, por favor.");
		return (1);
    }
    i = 0;
    while (argv[++i])
    {
        ft_printf("%d\n", i);
        ft_check(i, argv);
    }
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

