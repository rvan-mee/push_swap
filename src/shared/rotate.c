/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 18:47:41 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/07/11 16:59:54 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

// Reverse rotates both lists.
void	reverse_rotate_both_lst(t_list **head_a, t_list **head_b, int print)
{
	reverse_rotate_lst(head_a, NULL);
	reverse_rotate_lst(head_b, NULL);
	if (print == 1)
		write(1, "rrr\n", 4);
}

// Rotates both lists.
void	rotate_both_lst(t_list **head_a, t_list **head_b, int print)
{
	rotate_lst(head_a, NULL);
	rotate_lst(head_b, NULL);
	if (print == 1)
		write(1, "rr\n", 3);
}

// Rotates the last node of the list to the front.
void	reverse_rotate_lst(t_list **head_lst, char *str)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*head_lst) < 2)
		return ;
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

// Rotates the first node of the list to the end.
void	rotate_lst(t_list **head_lst, char *str)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*head_lst) < 2)
		return ;
	last = ft_lstlast(*head_lst);
	tmp = *head_lst;
	last->next = tmp;
	*head_lst = (*head_lst)->next;
	tmp->next = NULL;
	if (str)
		write(1, str, ft_strlen(str));
}
