/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/05 15:17:54 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/22 17:06:19 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "libft/libft.h"

int		is_sorted(t_list *lst);
int		lowest_half(t_list **head_a, int lowest);
int		last_pos(t_list **head_a);
void	input_check(int *argc, char **argv, t_list **a);
void	duplicate_check(t_list *a);
void	exit_with_error(char *error);
void	fill_stack(t_list **a, int num);
void	position_sort(t_list *a, int sort_amount);
void	sort_lst(t_list **head_a, t_list **head_b, int argc);
void	sort_3(t_list **head_a);
void	sort_4(t_list **head_a, t_list **head_b);
void	sort_5(t_list **head_a, t_list **head_b);
void	push_lst(t_list **take, t_list **push, char *str);
void	reverse_rotate_lst(t_list **head_lst, char *str);
void	reverse_rotate_both_lst(t_list **head_a, t_list **head_b);
void	rotate_lst(t_list **head_lst, char *str);
void	rotate_both_lst(t_list **head_a, t_list **head_b);
void	swap_lst(t_list **head_lst, char *str);
void	swap_both_lst(t_list **head_a, t_list **head_b);
void	get_lowest(t_list **head_a, t_list **head_b);

void	print_lists(t_list *head_a, t_list *head_b);

#endif
