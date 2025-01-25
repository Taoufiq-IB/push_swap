
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:58:00 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/25 18:00:11 by tibarike         ###   ########.fr       */
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

	i = 0;
	result = 0;
	while (nb[i] == ' ')
		i++;
	signal = get_signal(nb, &i);
	if (!nb[i])
		(write(2, "Error\n", 6), exit(1));
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		result = (result * 10) + (nb[i] - '0');
		if (result * signal > INT_MAX || result * signal < INT_MIN)
			(write(2, "Error\n", 6), exit(1));
		i++;
	}
	if (nb[i])
		(write(2, "Error\n", 6), exit(1));
	return (result * signal);
}
