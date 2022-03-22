/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 13:12:12 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/05 15:08:51 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*newlst;
	t_list	*current;

	if (!lst)
		return (0);
	newlst = ft_lstnew(f(lst->num));
	if (newlst == 0)
		return (0);
	current = newlst;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew(f(lst->num));
		current = current->next;
		if (current == 0)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		lst = lst->next;
	}
	return (newlst);
}
