#include "stack.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del && lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}	

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*next;

	node = *lst;
	while (node && del)
	{
		next = node->next;
		ft_lstdelone(node, del);
		node = next;
	}
	*lst = NULL;
}

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