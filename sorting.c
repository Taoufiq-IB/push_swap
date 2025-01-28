/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:21:14 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/28 11:55:35 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_less(s_stack **a, s_stack **b)
{
	if (ft_stacksize(*a) == 2)
		sa(a, 1);
	else if (ft_stacksize(*a) == 3)
		sort3(a);
	else if (ft_stacksize(*a) == 4)
		sort4(a, b);
	else 
		sort5(a, b);
}

void	sort3(s_stack **a)
{
	s_stack *max;

	max = get_max(*a);
	if (*a == max)
		ra(a, 1);
	if ((*a)->next == max)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	sort4(s_stack **a, s_stack **b)
{
	s_stack	*min;
	
	min = get_min(*a);
	while ((*a)->value != min->value)
		rra(a, 1);
	pb(a, b);
	sort3(a);
	pa(a, b);
}

void	sort5(s_stack **a, s_stack **b)
{
	s_stack	*min;

	min = get_min(*a);
	while ((*a)->value != min->value)
	{
		if ((*a)->next == min)
		{			
			ra(a, 1);
			break;
		}
		rra(a, 1);
	}
	pb(a, b);
	sort4(a, b);
	pa(a, b);
}

void	push_to_b(s_stack **a, s_stack **b)
{
	int		range;
	int		i;
	s_stack	*tmp;
	
	range = 16;
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

void	push_to_a(s_stack **a, s_stack **b)
{
	
}