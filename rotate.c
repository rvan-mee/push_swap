/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 18:47:41 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/22 17:07:09 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_both_lst(t_list **head_a, t_list **head_b)
{
	reverse_rotate_lst(head_a, NULL);
	reverse_rotate_lst(head_b, "rrr\n");
}

void	rotate_both_lst(t_list **head_a, t_list **head_b)
{
	rotate_lst(head_a, NULL);
	rotate_lst(head_b, "rr\n");
}

void	reverse_rotate_lst(t_list **head_lst, char *str)
{
	t_list	*tmp;
	t_list	*last;

	last = ft_lstlast(*head_lst);
	tmp = *head_lst;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *head_lst;
	*head_lst = last;
	if (str)
		write(1, str, ft_strlen(str));
}

void	rotate_lst(t_list **head_lst, char *str)
{
	t_list	*tmp;
	t_list	*last;

	last = ft_lstlast(*head_lst);
	tmp = *head_lst;
	last->next = tmp;
	*head_lst = (*head_lst)->next;
	tmp->next = NULL;
	if (str)
		write(1, str, ft_strlen(str));
}
