/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:13:36 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/28 18:04:04 by rvan-mee      ########   odam.nl         */
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
		tmp =  tmp->next;
		count += 1;
	}
	return (count);
}

int	range_smallest_from_bot(int start_range, int end_range, t_list **head)
{
	t_list	*tmp;
	t_list	*check_next;
	int		count;

	check_next = ft_lstlast(*head);
	count = 0;
	if (check_next->pos >= start_range && check_next->pos <= end_range)
		return (0);
	while (1)
	{
		tmp = *head;
		while (tmp->next != check_next)
			tmp = tmp->next;
		count += 1;
		if (tmp->pos >= start_range && tmp->pos <= end_range)
			return (count);
		else if (tmp == *head)
			return (-1);
		check_next = tmp;
	}
}

void	small_sort_helper(t_list **head_a, t_list **head_b, int range_start, int range_end)
{
	int	top;
	int	bot;
	int	i;

	i = 0;
	printf("range end: %d, range start: %d\n", range_end, range_start);
	while (i < range_end - range_start)
	{
		printf("i = %d\n", i);
		bot = range_smallest_from_bot(range_start, range_end, head_a);
		top = range_smallest_from_top(range_start, range_end, head_a);
		// printf("top: %d\n", top);
		// printf("bot: %d\n", bot);
		if (top <= bot)
		{
			while (top > 0)
			{
				printf("top: %d\n", top);
				rotate_lst(head_a, "ra\n");
				top -= 1;
			}
		}
		else
		{
			while (bot > 0)
			{
				printf("bot: %d\n", bot);
				reverse_rotate_lst(head_a, "rra\n");
				bot -= 1;
			}
		}
		push_lst(head_a, head_b, "pb\n");
		i += 1;
	}
}

void	small_sort(t_list **head_a, t_list **head_b, int argc)
{
	int	i;
	int	start_range;
	int	end_range;

	i = 0;
	start_range = argc / 3;
	end_range = start_range;
	printf("total argc: %d\n", argc);
	while (i < 3)
	{
		small_sort_helper(head_a, head_b, start_range * i, end_range * (i + 1));
		i += 1;
		// if (i == 2 && argc / 3.0 / 1.0 > 0)
		// 	end_range += 1;
		printf("small sort helper runs: %d\n", i);
	}
	heighest_to_a(head_a, head_b);
	// print_lists(*head_a, *head_b);
	print_lists(*head_a, *head_b);
}
	// print_lists(*head_a, *head_b);
	// while ((*head_a) != NULL)
	// 	get_lowest(head_a, head_b);
	// while ((*head_b) != NULL)
	// 	push_lst(head_b, head_a, "pa\n");
