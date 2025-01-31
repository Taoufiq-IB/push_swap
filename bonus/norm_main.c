/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:15:50 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/31 15:16:18 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	handle_no_operations(t_stack *a)
{
	if (check_sorted(a) == 1)
	{
		ft_stackclear(&a);
		write(1, "OK\n", 3);
		return (0);
	}
	else
	{
		ft_stackclear(&a);
		write(1, "KO\n", 3);
		return (0);
	}
}

void	checks(char **argv, int *arr, int size)
{
	check_spaces(argv, arr);
	is_dup(arr, size);
}
