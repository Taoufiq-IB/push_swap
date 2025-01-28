/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:17:57 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/28 15:39:46 by tibarike         ###   ########.fr       */
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

int	ft_atoi(char *nb, int *success)
{
	int		i;
	long	result;
	int		signal;

	i = 0;
	result = 0;
	*success = 1;
	while (nb[i] == ' ')
		i++;
	signal = get_signal(nb, &i);
	if (!nb[i])
		return (*success = 0, 0);
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		result = (result * 10) + (nb[i] - '0');
		if (result * signal > INT_MAX || result * signal < INT_MIN)
			return (*success = 0, 0);
		i++;
	}
	if (nb[i])
		return (*success = 0, 0);
	return ((int)(result * signal));
}
