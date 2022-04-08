/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 12:01:27 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/08 19:08:10 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Improved push back b verion for radix to save on actions.
void	radix_sort_b(t_list **head_a, t_list **head_b, int i, int *reduce)
{
	t_bits	bit;

	bit.length = ft_lstsize(*head_b) - *reduce;
	*reduce = 0;
	while (bit.length)
	{
		bit_init(&bit, *head_a, *head_b, i);
		if (bit.b == 1)
			push_lst(head_b, head_a, "pa\n");
		else if (bit.b == 0 && bit.a == 1)
			rotate_lst(head_b, "rb\n");
		else if (bit.b == 0 && bit.a == 0)
		{
			rotate_both_lst(head_a, head_b);
			*reduce += 1;
		}
		bit.length -= 1;
	}
}

// If current bit is 0 push to b else rotate.
void	radix_sort_a(t_list **head_a, t_list **head_b, int i, int *reduce)
{
	int		length;

	length = ft_lstsize(*head_a) - *reduce;
	*reduce = 0;
	while (length > 0)
	{
		if (get_bit((*head_a)->pos, i) == 0)
			push_lst(head_a, head_b, "pb\n");
		// else if (get_bit((*head_a)->pos, i) == 1 && (*head_b != NULL && get_bit((*head_b)->pos, i) == 0))
		// 	rotate_lst(head_a, "ra\n");
		// else if (get_bit((*head_a)->pos, i) == 1 && (*head_b != NULL && get_bit((*head_b)->pos, i) == 1))
		// {
		// 	rotate_both_lst(head_a, head_b);
		// 	*reduce += 1;
		// }
		else 
			rotate_lst(head_a, "ra\n");
		length--;
	}
}

// Improved bitwise radix sort.
void	radix_sort(t_list **head_a, t_list **head_b, int argc)
{
	int		shift_amount;
	int		reduce;
	int		reduce_c = 0;
	int		i;

	i = 0;
	shift_amount = get_shift_amount(argc);
	while (i < shift_amount)
	{
		radix_sort_a(head_a, head_b, i, &reduce);
		reduce_c += reduce;
		if (i != shift_amount - 1)
		{
			radix_sort_b(head_a, head_b, i, &reduce);
			reduce_c += reduce;
		}
		i++;
	}
	while (*head_a != NULL)
	{
		if ((*head_a)->pos != argc)
			push_lst(head_a, head_b, "pb\n");
		else
			rotate_lst(head_a, "ra\n");
	}
	// sort_to_a(head_a, head_b);
	heighest_to_a(head_a, head_b);
	// printf("reduce_c = %d, argc = %d\n", reduce_c, argc);
}
