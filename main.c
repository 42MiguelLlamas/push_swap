#include <stdio.h>

t_element	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = (t_list *) malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	item ->content = content;
	item ->next = NULL;
	return (item);
}
int main(int argc, char **argv)
{
	if (argc != 2)
		return (NULL);
	printf ("%s\n", "hola");
  	return (0);
}
