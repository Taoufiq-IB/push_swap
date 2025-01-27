/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:39:50 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/27 16:50:57 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(s_stack **a, s_stack *new)
{
	s_stack	*last_n;
	s_stack *curr;

	if (!a || !new)
		return ;
	curr = *a;
	while (curr)
	{
		if (curr->value > new->value)
			curr->index++;
		else
			new->index++;
		curr = curr->next;
	}
	if (*a == NULL)
	{
		*a = new;
		return ;
	}
	last_n = ft_stacklast(*a);
	last_n->next = new;
}

s_stack	*ft_stacknew(int value, int index)
{
	s_stack	*tmp;

	tmp = malloc(sizeof(s_stack));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->index = index;
	tmp->next = NULL;
	return (tmp);
}

int	ft_stacksize(s_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

s_stack	*ft_stacklast(s_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackclear(s_stack **stack)
{
	s_stack	*crnt;
	s_stack	*tmp;

	if (!stack)
		return ;
	crnt = *stack;
	while (crnt != NULL)
	{
		tmp = crnt;
		crnt = crnt->next;
		free(tmp);
	}
	*stack = NULL;
}

int check_sorted(s_stack *stack)
{
	s_stack *tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_dup(s_stack *a)
{
	s_stack	*current;
	s_stack	*checker;

	if (!a)
		return (0);
	current = a;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (0);
			checker = checker->next;
		}
		current = current->next;
	}
	return (1);
}

s_stack	*get_max(s_stack *stack)
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
	return(tmp);
}

s_stack	*get_min(s_stack *stack)
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
	return(tmp);
}

