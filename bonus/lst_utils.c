/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:28:48 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/31 15:21:23 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **a, t_stack *new)
{
	t_stack	*last_n;
	t_stack	*curr;

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

t_stack	*ft_stacknew(int value, int index)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->index = index;
	tmp->next = NULL;
	return (tmp);
}

int	ft_stacksize(t_stack *stack)
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

void	ft_stackclear(t_stack **stack)
{
	t_stack	*crnt;
	t_stack	*tmp;

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
