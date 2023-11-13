#include "stack.h"

t_element	*ft_lstnew(int num)
{
	t_element	*elem;

	elem = (t_element *) malloc(sizeof(t_element));
	if (!elem)
		return (NULL);
	elem ->num = number;
	elem ->next = NULL;
	return (elem);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf ("%s\n", "hola");
  	return (0);
}
