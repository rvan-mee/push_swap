/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 18:52:11 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/03/22 17:07:09 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_lst(t_list **take, t_list **push, char *str)
{
	t_list	*new;
	t_list	*old;

	if (!take)
		return ;
	new = malloc(sizeof(t_list));
	if (!new)
		exit_with_error("Error\n");
	new->num = (*take)->num;
	new->pos = (*take)->pos;
	new->next = NULL;
	if (*push)
		new->next = *push;
	*push = new;
	old = *take;
	*take = (*take)->next;
	free(old);
	if (str)
		write(1, str, ft_strlen(str));
}
