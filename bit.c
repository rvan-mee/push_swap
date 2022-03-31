/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bit.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 17:57:19 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/31 19:06:19 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_shift_amount(int num)
{
	int	shift;

	shift = 0;
	while (num != 0)
	{
		num /= 2;
		shift += 1;
	}
	return (shift);
}

int	get_bit(int num, int shift)
{
	num = num >> shift;
	num = num & 1;
	return (num | 0);
}

void	bit_init(t_bits *bits, t_list *head_a, t_list *head_b, int i)
{
	bits->a = get_bit(head_a->pos, i + 1);
	bits->b = get_bit(head_b->pos, i + 1);
	bits->b_next = get_bit(head_b->pos, i + 2);
}
