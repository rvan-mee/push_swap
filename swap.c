/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 10:46:37 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/22 17:07:10 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both_lst(t_list **head_a, t_list **head_b)
{
	swap_lst(head_a, NULL);
	swap_lst(head_b, "ss\n");
}

void	swap_lst(t_list **head_lst, char *str)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if ((*head_lst) == NULL || (*head_lst)->next == NULL)
		return ;
	tmp1 = (*head_lst);
	tmp2 = (*head_lst)->next;
	tmp3 = (*head_lst)->next->next;
	(*head_lst) = tmp2;
	tmp2->next = tmp1;
	tmp1->next = tmp3;
	if (str)
		write(1, str, ft_strlen(str));
}
