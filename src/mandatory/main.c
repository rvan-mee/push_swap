/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 15:17:56 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/11 15:08:48 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Call all functions in proper order. 
int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	if (argc == 1)
		return (0);
	head_a = NULL;
	head_b = NULL;
	input_check(&argc, argv, &head_a);
	position_sort(head_a, argc);
	duplicate_check(head_a);
	if (is_sorted(head_a))
		return (0);
	sort_lst(&head_a, &head_b, argc);
	return (0);
}
