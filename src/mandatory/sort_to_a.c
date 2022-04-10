/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_to_a.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 14:33:05 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/09 19:43:02 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

// Returns the amount of rotations it would take
// for pos to fit on the correct position within list a.
int	get_move_count_a(t_list *lst_a, int pos)
{
	t_list	*after;
	int		before;
	int		moves;
	int		heighest;
	int		lowest;

	moves = 0;
	after = lst_a;
	before = last_pos(&lst_a);
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
	if (moves > ft_lstsize(lst_a) / 2)
			moves = (ft_lstsize(lst_a) - moves) * -1;
	return (moves);
}

// Retruns the total amount of moves it would take
// for pos to land on the correct position within a.
int	get_move_count_b(t_list *b, int pos)
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
		moves = (lst_size - moves) * -1;
	return (moves);
}

// Resets all values in moves.
void	reset_moves(t_moves *moves)
{
	moves->current_a = INT_MAX / 2;
	moves->current_b = INT_MAX / 2;
	moves->least_a = INT_MAX / 2;
	moves->least_b = INT_MAX / 2;
	moves->best_pos = INT_MAX / 2;
}

// Checks if the current move is more efficient then the
// last best move found.
void	check_moves(t_moves *moves, int pos)
{
	if (ft_abs(moves->current_a) + ft_abs(moves->current_b)
		< ft_abs(moves->least_a) + ft_abs(moves->least_b))
	{
		moves->least_a = moves->current_a;
		moves->least_b = moves->current_b;
		moves->best_pos = pos;
	}
}

// Finds the least amount of moves for a node in list b 
// to get on the proper place in list a, repeats till list b is empty.
void	sort_to_a(t_list **head_a, t_list **head_b)
{
	t_moves	moves;
	t_list	*tmp;

	while (ft_lstsize(*head_a) < 2)
		push_lst(head_b, head_a, "pa\n");
	while (*head_b != NULL)
	{
		reset_moves(&moves);
		tmp = *head_b;
		while (tmp != NULL)
		{
			moves.current_b = get_move_count_b(*head_b, tmp->pos);
			moves.current_a = get_move_count_a(*head_a, tmp->pos);
			check_moves(&moves, tmp->pos);
			tmp = tmp->next;
		}
		rotate_optimize(head_a, head_b, &moves);
		rotate_till_pos(head_b, moves.best_pos);
		rotate_pushback(head_a, head_b, moves.best_pos);
	}
	rotate_after_sorted(head_a);
}
