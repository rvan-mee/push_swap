/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 12:01:27 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/31 19:08:26 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// // if bit is 0 push to b till list size = 0
// // check next bit in b, if its 1 push back to a, else rotate b, if current a is also a 1 double rotate b and a 
// // else push a to b and rotate?
// // continue till a is empty?
// // reverse push b into a

// printf("length of list b: %d\n", length);
// printf("get bit returns: %d with number: %d with shift %d\n", bit_b, (*head_b)->pos, i);
void	radix_sort_b(t_list **head_a, t_list **head_b, int i, int *a_reduce)
{
	t_bits	bit;
	int		size_a;

	bit.length = ft_lstsize(*head_b);
	size_a = ft_lstsize(*head_a);
	while (bit.length)
	{
		bit_init(&bit, *head_a, *head_b, i);
		if (bit.b == 1)
			push_lst(head_b, head_a, "pa\n");
		else if (bit.b == 0)
			rotate_lst(head_b, "rb\n");
		// else if (bit.b == 0 && bit.a == 1 && size_a > 0)
		// {
		// 	rotate_both_lst(head_a, head_b);
		// 	size_a--;
		// 	*a_reduce += 1;
		// }
		bit.length -= 1;
	}
	*a_reduce += 0;
}

// printf("lentgh a: %d current number: %d current bit return with: %d shift: %d\n", length, (*head_a)->pos, get_bit((*head_a)->pos, i), i);
void	radix_sort_a(t_list **head_a, t_list **head_b, int i, int *reduce)
{
	int		length;

	length = ft_lstsize(*head_a) - *reduce;
	while (length > 0)
	{
		if (get_bit((*head_a)->pos, i) == 0)
			push_lst(head_a, head_b, "pb\n");
		else
			rotate_lst(head_a, "ra\n");
		length--;
	}
	*reduce = 0;
}

void	radix_sort(t_list **head_a, t_list **head_b, int argc)
{
	int		shift_amount;
	int		a_reduce;
	int		i;

	i = 0;
	shift_amount = get_shift_amount(argc);
	while (i < shift_amount)
	{
		radix_sort_a(head_a, head_b, i, &a_reduce);
		if (i != shift_amount - 1)
			radix_sort_b(head_a, head_b, i, &a_reduce);
		i++;
	}
	while (*head_a != NULL)
		push_lst(head_a, head_b, "pb\n");
	heighest_to_a(head_a, head_b);
	}
