/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-mee <rvan-mee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:11:10 by rvan-mee          #+#    #+#             */
/*   Updated: 2022/04/09 18:03:28 by rvan-mee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long	ft_atoi(const char *nptr)
{
	long	c;
	int		value;

	c = 0;
	value = 1;
	while (*nptr != '\0' && ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			value *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		c *= 10;
		c += *nptr - 48;
		nptr++;
	}
	if (*nptr != '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (c * value);
}
