/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_a_helper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 17:07:05 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/10 15:47:07 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotates the list to have 0 set in the first node.
void	rotate_after_sorted(t_list **head_a)
{
	if (lowest_half(head_a, 0) == 1)
		while ((*head_a)->pos != 0)
			rotate_lst(head_a, "ra\n");
	else
		while ((*head_a)->pos != 0)
			reverse_rotate_lst(head_a, "rra\n");
}

// Rotates or reverse rotates list a till the pos in b 
// can be pushed to the top and then does so.
void	rotate_pushback(t_list **head_a, t_list **head_b, int pos)
{
	int	rotate;

	rotate = get_move_count_a(*head_a, pos);
	if (rotate > 0)
	{
		while (rotate > 0)
		{	
			rotate_lst(head_a, "ra\n");
			rotate -= 1;
		}
	}
	else
	{
		while (rotate < 0)
		{
			reverse_rotate_lst(head_a, "rra\n");
			rotate += 1;
		}
	}
	push_lst(head_b, head_a, "pa\n");
}

// Checks if its possible to rotate both lists
// at the same time and then does so.
void	rotate_optimize(t_list **head_a, t_list **head_b, t_moves *moves)
{
	while (moves->least_a < 0 && moves->least_b < 0)
	{
		reverse_rotate_both_lst(head_a, head_b, 1);
		moves->least_a += 1;
		moves->least_b += 1;
	}
	while (moves->least_a > 0 && moves->least_b > 0)
	{
		rotate_both_lst(head_a, head_b, 1);
		moves->least_a -= 1;
		moves->least_b -= 1;
	}
}

// simple ABS function.
int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

// Rotates the given list to have the given pos on top.
void	rotate_till_pos(t_list **head_b, int pos)
{
	t_list	*tmp;
	int		rotate;

	rotate = 0;
	tmp = (*head_b);
	while (tmp != NULL && tmp->pos != pos)
	{
		tmp = tmp->next;
		rotate += 1;
	}
	if (rotate > ft_lstsize(*head_b) / 2)
	{
		while ((*head_b)->pos != pos)
			reverse_rotate_lst(head_b, "rrb\n");
	}
	else
	{
		while ((*head_b)->pos != pos)
		{
			if ((*head_b)->next->pos == pos)
				swap_lst(head_b, "sb\n");
			else
				rotate_lst(head_b, "rb\n");
		}
	}
}
