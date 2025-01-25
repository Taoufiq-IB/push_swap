/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:59:27 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/24 17:24:17 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_signal(const char *nb, int *index)
{
	int	signal;

	signal = 1;
	if (nb[*index] == '-' || nb[*index] == '+')
	{
		if (nb[*index] == '-')
			signal *= -1;
		(*index)++;
	}
	return (signal);
}

int	ft_atoi(char *nb)
{
	int		i;
	long	result;
	int		signal;
	long	check;

	i = 0;
	result = 0;
	while (nb[i] == ' ')
		i++;
	signal = get_signal(nb, &i);
	if (!(nb[i] >= '0' && nb[i] <= '9'))
		(write(2, "Error\n", 6), exit(1));
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		result = (result * 10) + (nb[i++] - '0');
		if (result * signal > INT_MAX || result * signal < INT_MIN)
		{
			(write(2, "Error\n", 6), exit(1));
		}
	}
	return (result * signal);
}
// int main(int argc, char **argv)
// {
// 	int i = 1;
// 	while (i < argc)
// 	{
// 		printf("%d\n", ft_atoi(argv[i]));
// 		i++;
// 	}
// 	return 0;
// }
