/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/09 14:48:06 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/10 13:47:53 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H
# include "../../libft/libft.h"

void	push_lst(t_list **take, t_list **push, char *str);
void	reverse_rotate_lst(t_list **head_lst, char *str);
void	reverse_rotate_both_lst(t_list **head_a, t_list **head_b, int print);
void	rotate_lst(t_list **head_lst, char *str);
void	rotate_both_lst(t_list **head_a, t_list **head_b, int print);
void	swap_lst(t_list **head_lst, char *str);
void	swap_both_lst(t_list **head_a, t_list **head_b, int print);
void	input_check(int *argc, char **argv, t_list **a);
void	duplicate_check(t_list *a);
void	exit_with_error(char *error);
void	fill_stack(t_list **a, int num);
void	position_sort(t_list *a, int sort_amount);
int		is_sorted(t_list *lst);

#endif
