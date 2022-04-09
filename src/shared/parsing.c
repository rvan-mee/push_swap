/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 18:49:33 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/09 18:03:17 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

// Uses free() on a char ** to free all srtings.
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != '\0')
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Checks if the given list is sorted.
int	is_sorted(t_list *lst)
{
	int	prev;

	prev = lst->pos;
	lst = lst->next;
	while (lst != NULL)
	{
		if (lst->pos != prev + 1)
			return (0);
		prev = lst->pos;
		lst = lst->next;
	}
	return (1);
}

// Writes the given string on the stderr before exiting the program.
void	exit_with_error(char *error)
{
	write(2, error, ft_strlen(error));
	exit(1);
}

// Checks if there is a -1 left in the list 
// indicating a duplicate number.
void	duplicate_check(t_list *a)
{
	while (a != NULL)
	{
		if (a->pos == -1)
			exit_with_error("Error\n");
		a = a->next;
	}
}

// Checks the input and instantly adds it to list a.
void	input_check(int *argc, char **argv, t_list **a)
{
	int		i;
	int		j;
	int		count;
	char	**nums;
	long	temp;

	i = 1;
	count = *argc;
	*argc = 0;
	while (i < count)
	{
		j = 0;
		nums = ft_split(argv[i], ' ');
		while (nums[j] != '\0')
		{
			temp = ft_atoi(nums[j]);
			if (temp > INT_MAX || temp < INT_MIN)
				exit_with_error("Error\n");
			ft_lstadd_back(a, ft_lstnew(temp));
			j++;
			*argc += 1;
		}
		free_split(nums);
		i++;
	}
}
