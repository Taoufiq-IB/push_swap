/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_less.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:36:36 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/28 14:40:36 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_less(t_stack **a, t_stack **b)
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

void	sort3(t_stack **a)
{
	t_stack	*max;

	max = get_max(*a);
	if (*a == max)
		ra(a, 1);
	if ((*a)->next == max)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

void	sort4(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = get_min(*a);
	while ((*a)->value != min->value)
		rra(a, 1);
	pb(a, b);
	sort3(a);
	pa(a, b);
}

void	sort5(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = get_min(*a);
	while ((*a)->value != min->value)
	{
		if ((*a)->next == min)
		{			
			ra(a, 1);
			break ;
		}
		rra(a, 1);
	}
	pb(a, b);
	sort4(a, b);
	pa(a, b);
}
