/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:13:36 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/31 16:58:34 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	range_smallest_from_top(int start_range, int end_range, t_list **head)
{
	t_list	*tmp;
	int		count;

	tmp = *head;
	count = 0;
	while (tmp != NULL && (tmp->pos < start_range || tmp->pos > end_range))
	{
		tmp = tmp->next;
		count += 1;
	}
	return (count);
}

int	range_smallest_from_bot(int start_range, int end_range, t_list **head)
{
	t_list	*tmp;
	int		count;
	int		lst_size;
	int		current_count;

	count = 0;
	current_count = 0;
	tmp = *head;
	lst_size = ft_lstsize(*head);
	while (tmp->next != NULL)
	{
		if (tmp->pos >= start_range && tmp->pos <= end_range)
			count = current_count;
		current_count += 1;
		tmp = tmp->next;
	}
	return (lst_size - count);
}

void	small_sort_rotate(t_list **head_a, int top, int bot, int selection)
{
	if (selection == 1)
	{
		while (top > 0)
		{
			rotate_lst(head_a, "ra\n");
			top -= 1;
		}
	}
	else
	{
		while (bot > 0)
		{
			reverse_rotate_lst(head_a, "rra\n");
			bot -= 1;
		}
	}
}

void	sort_helper(t_list **head_a, t_list **head_b, int range_s, int range_e)
{
	int	top;
	int	bot;
	int	i;

	i = 0;
	while (i < range_e - range_s)
	{
		bot = range_smallest_from_bot(range_s, range_e, head_a);
		top = range_smallest_from_top(range_s, range_e, head_a);
		if (top <= bot)
			small_sort_rotate(head_a, top, bot, 1);
		else if (top > bot && bot != 0)
			small_sort_rotate(head_a, top, bot, 2);
		else if (bot == 0)
			reverse_rotate_lst(head_a, "rra\n");
		push_lst(head_a, head_b, "pb\n");
		i += 1;
	}
}

void	small_sort(t_list **head_a, t_list **head_b, int argc)
{
	int	pre_sort_stacks;
	int	range;
	int	offset;
	int	i;

	i = 0;
	offset = 0;
	pre_sort_stacks = argc / 2 / 10 + 1;
	range = argc / pre_sort_stacks;
	while (i < pre_sort_stacks)
	{
		sort_helper(head_a, head_b, range * i, range * (i + 1) + offset);
		i += 1;
		if (i == pre_sort_stacks - 1)
			offset += argc % pre_sort_stacks;
	}
	heighest_to_a(head_a, head_b);
}
