/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 15:17:56 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/08 14:07:49 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Prints the contents of both lists.
void	print_lists(t_list *head_a, t_list *head_b)
{
	t_list	*tmp;
	int		count;

	tmp = head_a;
	count = 0;
	printf("\n");
	while (tmp != NULL)
	{
		printf("position: %d is %d from top\n", tmp->pos, count);
		tmp = tmp->next;
		count++;
	}
	tmp = head_b;
	printf("\n");
	count  = 0;
	while (tmp != NULL)
	{
		printf("position: %d is %d from top\n", tmp->pos, count);
		tmp = tmp->next;
		count++;
	}
}

// Call all functions in proper order. 
int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	if (argc == 1)
		return (0);
	head_a = NULL;
	head_b = NULL;
	setbuf(stdout, 0);
	input_check(&argc, argv, &head_a);
	position_sort(head_a, argc);
	duplicate_check(head_a);
	if (is_sorted(head_a))
		return (0);
	sort_lst(&head_a, &head_b, argc);
	return (0);
}
	// if (is_sorted(head_a) && head_b == NULL)
	// 	printf("list is sorted!\n");
	// print_lists(head_a, head_b);
	// system("leaks push_swap");
