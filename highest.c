/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   highest.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 16:47:12 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/06 13:59:22 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns the position inside the last node of the list;
int	last_pos(t_list **head)
{
	t_list	*tmp;

	tmp = ft_lstlast(*head);
	return (tmp->pos);
}

// Returns the heighest number in the list.
int	get_heighest(t_list **head)
{
	int		current_heighest;
	int		i;
	t_list	*tmp;

	i = 0;
	current_heighest = INT_MIN;
	tmp = (*head);
	while (tmp != NULL)
	{
		if (tmp->pos > current_heighest)
			current_heighest = tmp->pos;
		tmp = tmp->next;
	}
	return (current_heighest);
}

// Pushes the heighest position of b to a.
void	heighest_to_a(t_list **head_a, t_list **head_b)
{
	int		heighest;

	while (*head_b != NULL)
	{
		heighest = get_heighest(head_b);
		if (lowest_half(head_b, heighest) == 1)
		{
			while ((*head_b)->pos != heighest)
			{
				if ((*head_b)->next->pos != heighest)
					rotate_lst(head_b, "rb\n");
				else
					swap_lst(head_b, "sb\n");
			}
			push_lst(head_b, head_a, "pa\n");
		}
		else
		{
			while ((*head_b)->pos != heighest)
				reverse_rotate_lst(head_b, "rrb\n");
			push_lst(head_b, head_a, "pa\n");
		}
	}
}
