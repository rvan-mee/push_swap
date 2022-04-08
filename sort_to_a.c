/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_to_a.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 14:33:05 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/08 15:56:17 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#define TRUE 1
#define FALSE 0
int rotate_front = 0;
int rotate_back = 0;
int	max_rotate_back = 0;

// Returns the amount of rotations it would take for pos to fit on the correct position within list a.
// If check_reverse is true it will return the amount from bottom if its lower.
int	get_rotate_count_a(t_list *lst_a, int pos, int check_reverse)
{
	t_list	*after;
	int		before;
	int		moves;
	int		heighest;
	int		lowest;

	moves = 0;
	after = ft_lstlast(lst_a);
	before = after->pos;
	after = lst_a;
	heighest = get_heighest(&lst_a);
	lowest = get_lowest(&lst_a);
	while (after != NULL)
	{
		if ((pos > before && pos < after->pos)
			|| (before == heighest && pos > heighest)
			|| (after->pos == lowest && pos < after->pos))
			break ;
		before = after->pos;
		after = after->next;
		moves += 1;
	}
	if ((check_reverse == TRUE) && (moves > ft_lstsize(lst_a) / 2))
			moves = ft_lstsize(lst_a) - moves;
	return (moves);
}

// Retruns the total amount of moves it would take for pos to land on the correct position within a.
int	get_move_count(t_list *a, t_list *b, int pos)
{
	t_list	*tmp;
	int		moves;
	int		lst_size;

	moves = 0;
	tmp = b;
	lst_size = ft_lstsize(b);
	while (tmp->pos != pos)
	{
		tmp = tmp->next;
		moves += 1;
	}
	if (moves > lst_size / 2)
		moves = lst_size - moves;
	return (get_rotate_count_a(a, pos, TRUE) + moves);
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
		rotate = ft_lstsize(*head_b) - rotate;
		while ((*head_b)->pos != pos)
			reverse_rotate_lst(head_b, "rrb\n");
	}
	else
		while ((*head_b)->pos != pos)
		{
			if ((*head_b)->next->pos == pos)
				swap_lst(head_b, "sb\n");
			else
				rotate_lst(head_b, "rb\n");
		}
}

// Rotates or reverse rotates a till the pos in b can be pushed to the top and then does so.
void	rotate_pushback(t_list **head_a, t_list **head_b, int pos)
{
	int	rotate;
	int	rotate_debug;

	rotate = get_rotate_count_a(*head_a, pos, FALSE);
	rotate_debug = rotate;
	if (rotate <= ft_lstsize(*head_a) / 2)
	{
		while (rotate > 0)
		{	
			rotate_lst(head_a, "ra\n");
			rotate -= 1;
		}
	}
	else
	{
		rotate = ft_lstsize(*head_a) - rotate;
		while (rotate > 0)
		{
			reverse_rotate_lst(head_a, "rra\n");
			rotate -= 1;
		}
	}
	push_lst(head_b, head_a, "pa\n");
}


	// debugging
	// t_list *printing;
	// printing = ft_lstlast(*head_a);
	// if (ft_lstsize(*head_a) > 1)
	// {
	// 	if (ft_lstsize(*head_a) > 2
	// 		&& (((printing->pos > (*head_a)->pos) && printing->pos != get_heighest(head_a))
	// 		|| (((*head_a)->pos > (*head_a)->next->pos) && (*head_a)->next->pos != get_lowest(head_a))))
	// 	{
	// 		printf("\npos after push: %d - %d - %d, incoming pos: %d\n", printing->pos, (*head_a)->pos, (*head_a)->next->pos, pos);
	// 		printf("heighest in list: %d current: %d lowest: %d\n", get_heighest(head_a), (*head_a)->pos, get_lowest(head_a));
	// 		if (rotate_debug <= ft_lstsize(*head_a) / 2)
	// 			rotate_front += 1;
	// 		else
	// 			rotate_back += 1;
	// 		printf("rotate: %d, reverse rotate: %d max rotate back: %d\n", rotate_front, rotate_back, max_rotate_back);
	// 		printf("\n\n\nerror??\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	// 	}
	// }




void	rotate_after_sorted(t_list **head_a)
{
	if (lowest_half(head_a, 0) == 1)
		while ((*head_a)->pos != 0)
			rotate_lst(head_a, "ra\n");
	else
		while ((*head_a)->pos != 0)
			reverse_rotate_lst(head_a, "rra\n");
}

// printf("best pos found is %d with %d move(s)\n", best_pos, least + 1);

// Finds the least amount of moves for a node in list b to get on the proper place in list a,
// repeats till list b is empty.
void	sort_to_a(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	int		best_pos;
	int		moves;
	int		least;

	while (ft_lstsize(*head_a) < 2)
		push_lst(head_b, head_a, "pa\n");
	while (*head_b != NULL)
	{
		least = INT_MAX;
		tmp = *head_b;
		while (tmp != NULL)
		{
			moves = get_move_count(*head_a, *head_b, tmp->pos);
			if (moves < least)
			{
				least = moves;
				best_pos = tmp->pos;
			}
			tmp = tmp->next;
		}
		rotate_till_pos(head_b, best_pos);
		rotate_pushback(head_a, head_b, best_pos);
	}
	rotate_after_sorted(head_a);
}
