/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-mee <rvan-mee@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/09 13:42:31 by rvan-mee      #+#    #+#                 */
/*   Updated: 2022/07/11 17:02:52 by rvan-mee      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../shared/shared.h"
#include <unistd.h>

// Checks the output for what function has to be run and does so.
void	preform_output(t_list **head_a, t_list **head_b, char *output)
{
	if (!ft_strncmp(output, "sa\n", 4))
		swap_lst(head_a, NULL);
	else if (!ft_strncmp(output, "sb\n", 4))
		swap_lst(head_b, NULL);
	else if (!ft_strncmp(output, "pa\n", 4))
		push_lst(head_b, head_a, NULL);
	else if (!ft_strncmp(output, "pb\n", 4))
		push_lst(head_a, head_b, NULL);
	else if (!ft_strncmp(output, "ra\n", 4))
		rotate_lst(head_a, NULL);
	else if (!ft_strncmp(output, "rb\n", 4))
		rotate_lst(head_b, NULL);
	else if (!ft_strncmp(output, "rra\n", 5))
		reverse_rotate_lst(head_a, NULL);
	else if (!ft_strncmp(output, "rrb\n", 5))
		reverse_rotate_lst(head_b, NULL);
	else if (!ft_strncmp(output, "ss\n", 4))
		swap_both_lst(head_a, head_b, 0);
	else if (!ft_strncmp(output, "rr\n", 4))
		rotate_both_lst(head_a, head_b, 0);
	else if (!ft_strncmp(output, "rrr\n", 5))
		reverse_rotate_both_lst(head_a, head_b, 0);
	else
		exit_with_error("ERROR\n");
}

// Checks if the list is properly sorted and if list b is emtpy.
void	check_if_sorted(t_list **head_a, t_list **head_b)
{
	if (*head_b != NULL || !is_sorted(*head_a))
		exit_with_error("KO\n");
	else
		write(1, "OK\n", 3);
}

// Checks if an error has occurred or if it is at the end of the file.
int	read_error_check(int bytes_read, int total_bytes_read, char *buffer)
{
	char	c;

	c = 'a';
	if (bytes_read == -1)
		exit_with_error("Read error\n");
	if (total_bytes_read > 5)
	{
		while (read(0, &c, 1) && c != '\n')
			;
		exit_with_error("ERROR\n");
	}
	if (bytes_read == 0 && buffer[0] == '\0')
	{
		free(buffer);
		return (1);
	}
	return (0);
}

// Reads the output of push_swap from stdin and retuns a string
// containing an instruction.
char	*read_output(void)
{
	int		total_bytes_read;
	int		bytes_read;
	char	*buffer;
	char	c;

	bytes_read = 0;
	total_bytes_read = 0;
	buffer = malloc(sizeof(char) * 6);
	if (buffer == NULL)
		exit_with_error("Malloc failed\n");
	buffer[0] = '\0';
	while (1)
	{
		bytes_read = read(0, &c, 1);
		total_bytes_read += bytes_read;
		if (read_error_check(bytes_read, total_bytes_read, buffer))
			return (NULL);
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

	if (argc == 1)
		return (0);
	input_check(&argc, argv, &stack_a);
	position_sort(stack_a, argc);
	duplicate_check(stack_a);
	while (1)
	{
		output = read_output();
		if (output == NULL)
			break ;
		preform_output(&stack_a, &stack_b, output);
		free(output);
	}
	check_if_sorted(&stack_a, &stack_b);
	return (0);
}
