/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 13:12:06 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/05 15:07:03 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list	*next;
	int		num;

	if (!lst)
		return ;
	next = lst->next;
	num = lst->num;
	while (next)
	{
		f(num);
		num = next->num;
		next = next->next;
	}
	f(num);
}
