/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:39:50 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/24 09:19:00 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_stack	get_max(s_stack	*stack)
{
	s_stack	*current;
	s_stack	*tmp;

	current = stack;
	tmp = current;
	while (current)
	{
		if (current->value > tmp->value)
			tmp = current;
		current = current->next;
	}
	return(*tmp);
}

s_stack	get_min(s_stack	*stack)
{
	s_stack	*current;
	s_stack	*tmp;

	current = stack;
	tmp = current;
	while (current)
	{
		if (current->value < tmp->value)
			tmp = current;
		current = current->next;
	}
	return(*tmp);
}

int check_sorted(s_stack *stack)
{
	s_stack *tmp;
	
	tmp = stack;
	while (tmp)
	{
		if (tmp->next != NULL)
		{
			if (tmp->value > tmp->next->value)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}