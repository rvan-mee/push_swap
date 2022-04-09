/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 15:17:54 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/09 15:25:40 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "../../libft/libft.h"
# include "../shared/shared.h"

// struct used for radix sort
typedef struct s_bits
{
	int	a;
	int	b;
	int	b_next;
	int	length;
}	t_bits;

// struct used for sort_to_a
typedef struct s_moves
{
	int	current_a;
	int	current_b;
	int	least_a;
	int	least_b;
	int	best_pos;
}	t_moves;

int		is_sorted(t_list *lst);
int		lowest_half(t_list **head, int lowest);
int		last_pos(t_list **head);
int		get_bit(int	num, int shift);
int		get_shift_amount(int num);
int		get_heighest(t_list **head);
int		get_lowest(t_list **head);
void	input_check(int *argc, char **argv, t_list **a);
void	duplicate_check(t_list *a);
void	exit_with_error(char *error);
void	fill_stack(t_list **a, int num);
void	position_sort(t_list *a, int sort_amount);
void	sort_lst(t_list **head_a, t_list **head_b, int argc);
void	sort_3(t_list **head_a);
void	sort_4(t_list **head_a, t_list **head_b);
void	sort_5(t_list **head_a, t_list **head_b);
void	bucket_sort(t_list **head_a, t_list **head_b, int argc);
void	quick_sort(t_list **head_a, t_list **head_b, int argc);
void	bit_init(t_bits *bits, t_list *head_a, t_list *head_b, int i);
void	radix_sort(t_list **head_a, t_list **head_b, int argc);
void	push_lowest(t_list **head_a, t_list **head_b);
void	heighest_to_a(t_list **head_a, t_list **head_b);

void	sort_to_a(t_list **head_a, t_list **head_b);
int		get_move_count_a(t_list *lst_a, int pos);
int		get_move_count_b(t_list *b, int pos);
void	sort_to_a(t_list **head_a, t_list **head_b);
void	rotate_till_pos(t_list **head_b, int pos);
void	rotate_after_sorted(t_list **head_a);
void	rotate_pushback(t_list **head_a, t_list **head_b, int pos);
void	rotate_optimize(t_list **head_a, t_list **head_b, t_moves *moves);

void	print_lists(t_list *head_a, t_list *head_b);

#endif
