/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 11:59:01 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/31 19:13:03 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_list **head_a, t_list **head_b)
{
	get_lowest(head_a, head_b);
	sort_4(head_a, head_b);
	push_lst(head_b, head_a, "pa\n");
}

void	sort_4(t_list **head_a, t_list **head_b)
{
	get_lowest(head_a, head_b);
	sort_3(head_a);
	push_lst(head_b, head_a, "pa\n");
}

void	sort_3(t_list **head_a)
{
	int	pos1;
	int	pos2;
	int	pos3;

	pos1 = (*head_a)->pos;
	pos2 = (*head_a)->next->pos;
	pos3 = (*head_a)->next->next->pos;
	if (pos1 > pos2 && pos1 < pos3)
		swap_lst(head_a, "sa\n");
	else if (pos1 > pos2 && pos2 < pos3)
		rotate_lst(head_a, "ra\n");
	else if (pos1 < pos2 && pos1 > pos3)
		reverse_rotate_lst(head_a, "rra\n");
	else if (pos1 > pos2 && pos2 > pos3)
	{
		rotate_lst(head_a, "ra\n");
		swap_lst(head_a, "sa\n");
	}
	else if (pos1 < pos3 && pos2 > pos3)
	{
		swap_lst(head_a, "sa\n");
		rotate_lst(head_a, "ra\n");
	}
}

void	sort_lst(t_list **head_a, t_list **head_b, int argc)
{
	if (argc == 2)
		swap_lst(head_a, "sa\n");
	else if (argc == 3)
		sort_3(head_a);
	else if (argc == 4)
		sort_4(head_a, head_b);
	else if (argc == 5)
		sort_5(head_a, head_b);
	else if (argc > 5 && argc <= 150)
		small_sort(head_a, head_b, argc);
	else
		radix_sort(head_a, head_b, argc);
}
	// && argc <= 150