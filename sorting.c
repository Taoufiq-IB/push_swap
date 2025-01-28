/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:21:14 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/28 17:28:55 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stack **a, t_stack **b, int i)
{
	int		range;
	t_stack	*tmp;

	if (ft_stacksize(*a) <= 100)
		range = 16;
	else
		range = 36;
	i = 0;
	while (*a)
	{
		tmp = *a;
		if (tmp->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if (tmp->index <= i + range)
		{
			pb(a, b);
			rb(b, 1);
			i++;
		}
		else
			ra(a, 1);
	}
}

static void	push_to_a(t_stack **a, t_stack **b)
{
	int	max_node_position;
	int	stack_size;

	stack_size = ft_stacksize(*b);
	while (stack_size > 0)
	{
		give_position(*b);
		max_node_position = get_max_element_position(*b);
		if (max_node_position < stack_size / 2)
			while ((*b)->position != max_node_position)
				rb(b, 1);
		else
			while ((*b)->position != max_node_position)
				rrb(b, 1);
		pa(a, b);
		stack_size--;
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	push_to_b(a, b, 0);
	push_to_a(a, b);
}
