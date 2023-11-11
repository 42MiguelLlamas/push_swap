#include "stack.h"

t_element	*ft_lstnew(void *content)
{
	t_element	*elem;

	elem = (t_element *) malloc(sizeof(t_element));
	if (!elem)
		return (NULL);
	elem ->key = content;
	elem ->next = NULL;
	return (elem);
}
