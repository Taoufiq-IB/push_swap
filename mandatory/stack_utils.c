/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:39:50 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/28 14:40:55 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	give_position(t_stack *b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = b;
	while (tmp)
	{
		tmp->position = i;
		i++;
		tmp = tmp->next;
	}
}

int	get_max_element_position(t_stack *stack)
{
	t_stack	*current;
	t_stack	*tmp;

	current = stack;
	tmp = current;
	while (current)
	{
		if (current->value > tmp->value)
			tmp = current;
		current = current->next;
	}
	return (tmp->position);
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*current;
	t_stack	*tmp;

	current = stack;
	tmp = current;
	while (current)
	{
		if (current->value > tmp->value)
			tmp = current;
		current = current->next;
	}
	return (tmp);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*current;
	t_stack	*tmp;

	current = stack;
	tmp = current;
	while (current)
	{
		if (current->value < tmp->value)
			tmp = current;
		current = current->next;
	}
	return (tmp);
}
