/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   position_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 18:51:21 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/04 15:43:59 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sets the position value of each number.
void	position_sort(t_list *a, int sort_amount)
{
	t_list	*tmp;
	t_list	*p_lowest;
	int		pos;
	long	current_lowest;
	long	old_lowest;

	pos = 0;
	old_lowest = LONG_MIN;
	while (pos < sort_amount)
	{
		current_lowest = LONG_MAX;
		tmp = a;
		while (tmp != NULL)
		{
			if (tmp->num > old_lowest && tmp->num < current_lowest)
			{
				current_lowest = tmp->num;
				p_lowest = tmp;
			}
			tmp = tmp->next;
		}
		p_lowest->pos = pos;
		old_lowest = current_lowest;
		pos += 1;
	}
}
