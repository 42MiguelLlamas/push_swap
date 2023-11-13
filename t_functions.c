#include "stack.h"

t_element	*ft_lstnew(int number)
{
	t_element	*elem;

	elem = (t_element *) malloc(sizeof(t_element));
	if (!elem)
		return (NULL);
	elem ->num = number;
	elem ->next = NULL;
	return (elem);
}