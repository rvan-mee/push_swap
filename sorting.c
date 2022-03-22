/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 11:59:01 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/22 17:24:03 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **head_a)
{
	if ((*head_a)->pos > (*head_a)->next->pos
		&& (*head_a)->pos > (*head_a)->next->next->pos)
		rotate_lst(head_a, "ra\n");
	if ((*head_a)->next->pos < (*head_a)->pos)
		swap_lst(head_a, "sa\n");
	if ((*head_a)->next->pos > (*head_a)->next->next->pos)
	{
		reverse_rotate_lst(head_a, "rra\n");
		if ((*head_a)->next->pos < (*head_a)->pos)
			swap_lst(head_a, "sa\n");
	}
	if ((*head_a)->next->pos > (*head_a)->next->next->pos)
		reverse_rotate_lst(head_a, "rra\n");
}

void	sort_lst(t_list **head_a, t_list **head_b, int argc)
{
	if (argc == 2)
		swap_lst(head_a, "sa\n");
	else if (argc == 3)
		sort_3(head_a);
	else if (argc == 4)
	{
		get_lowest(head_a, head_b);
		sort_3(head_a);
		push_lst(head_b, head_a, "pa\n");
	}
	else if (argc == 5)
	{
		
	}
	//system("leaks push_swap");
	// else if (argc => 6)
	// {}
}

void	reverse_sort_check(t_list **head_a)
{
	t_list	*tmp;
	int		last;

	tmp = (*head_a);
	last = tmp->pos;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (tmp->pos != last - 1)
			return ;
		last = tmp->pos;
		tmp = tmp->next;
	}
	while ((*head_a)->pos != 0)
		rotate_lst(head_a, "ra\n");
	exit (0);
}
