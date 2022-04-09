/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/09 13:42:31 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/04/09 19:31:04 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>

void	preform_output(t_list **head_a, t_list **head_b, char *output)
{
	if (!ft_strncmp(output, "sa\n", 4))
		swap_lst(head_a, "sa\n");
	else if (!ft_strncmp(output, "sb\n", 4))
		swap_lst(head_b, "sb\n");
	else if (!ft_strncmp(output, "pa\n", 4))
		push_lst(head_b, head_a, "pa\n");
	else if (!ft_strncmp(output, "pb\n", 4))
		push_lst(head_a, head_b, "pb\n");
	else if (!ft_strncmp(output, "ra\n", 4))
		rotate_lst(head_a, "ra\n");
	else if (!ft_strncmp(output, "rb\n", 4))
		rotate_lst(head_b, "rb\n");
	else if (!ft_strncmp(output, "rra\n", 5))
		reverse_rotate_lst(head_a, "rra\n");
	else if (!ft_strncmp(output, "rrb\n", 5))
		reverse_rotate_lst(head_b, "rrb\n");
	else if (!ft_strncmp(output, "ss\n", 4))
		swap_both_lst(head_a, head_b);
	else if (!ft_strncmp(output, "rr\n", 4))
		rotate_both_lst(head_a, head_b);
	else if (!ft_strncmp(output, "rrr\n", 5))
		reverse_rotate_both_lst(head_a, head_b);
	else
		exit_with_error("KO\n");
}

void	check_if_sorted(t_list **head_a, t_list **head_b)
{
	if (*head_b != NULL || !is_sorted(*head_a))
		exit_with_error("KO\n");
	else
		write(1, "OK\n", 3);
}

char	*read_output(int wait)
{
	int		total_bytes_read;
	int		bytes_read;
	char	*buffer;
	char	c;

	bytes_read = 0;
	total_bytes_read = 0;
	buffer = malloc(sizeof(char) * 7);
	if (buffer == NULL)
		exit_with_error("Malloc failed\n");
	buffer[0] = '\0';
	while (1)
	{
		if (wait == 1)
		{
			while (bytes_read == 0)
				bytes_read = read(0, &c, 1);
			wait = 0;
		}
		else
			bytes_read = read(0, &c, 1);
		total_bytes_read += bytes_read;
		if (bytes_read == -1)
			exit_with_error("Read error\n");
		if (total_bytes_read > 6)
			exit_with_error("KO\n");
		if (bytes_read == 0 && buffer[0] == '\0')
		{
			free(buffer);
			return (NULL);
		}
		buffer[total_bytes_read - 1] = c;
		buffer[total_bytes_read] = '\0';
		if (buffer[total_bytes_read - 1] == '\n')
			break ;
	}
	return (buffer);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*output;
	int		wait;

	input_check(&argc, argv, &stack_a);
	position_sort(stack_a, argc);
	wait = 1;
	while (1)
	{
		output = read_output(wait);
		if (output == NULL)
			break ;
		wait = 0;
		preform_output(&stack_a, &stack_b, output);
		free(output);
	}
	check_if_sorted(&stack_a, &stack_b);
	// system("leaks checker");
	return (0);
}
