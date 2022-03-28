/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lowest.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/22 16:50:46 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/28 16:47:10 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_pos(t_list **head_a)
{
	t_list	*tmp;

	tmp = (*head_a);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->pos);
}

int	current_lowest(t_list **head)
{
	int		current_lowest;
	int		i;
	t_list	*tmp;

	i = 0;
	current_lowest = INT_MAX;
	tmp = (*head);
	while (tmp != NULL)
	{
		if (tmp->pos < current_lowest)
			current_lowest = tmp->pos;
		tmp = tmp->next;
	}
	return (current_lowest);
}

int	lowest_half(t_list **head, int lowest)
{
	t_list	*tmp;
	int		list_size;
	int		i;

	i = 0;
	tmp = (*head);
	list_size = ft_lstsize((*head));
	while (tmp->pos != lowest && tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > list_size / 2)
		return (2);
	return (1);
}

void	get_lowest(t_list **head_a, t_list **head_b)
{
	t_list	*last;
	int		lowest;

	last = ft_lstlast((*head_a));
	lowest = current_lowest(head_a);
	if (lowest_half(head_a, lowest) == 1)
	{
		while ((*head_a)->pos != lowest)
			rotate_lst(head_a, "ra\n");
	}
	else
	{
		while ((*head_a)->pos != lowest)
			reverse_rotate_lst(head_a, "rra\n");
	}
	push_lst(head_a, head_b, "pb\n");
}
