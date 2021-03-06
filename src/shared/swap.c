/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-mee <rvan-mee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:46:37 by rvan-mee          #+#    #+#             */
/*   Updated: 2022/04/10 13:49:54 by rvan-mee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

// Swaps the first and second node in both lists respectivly.
void	swap_both_lst(t_list **head_a, t_list **head_b, int print)
{
	swap_lst(head_a, NULL);
	swap_lst(head_b, NULL);
	if (print == 1)
		write(1, "ss\n", 3);
}

// Swaps the first and second node in the given list.
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
