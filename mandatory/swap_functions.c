/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:16:36 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/28 14:41:03 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int i)
{
	t_stack	*tmp;
	t_stack	*na;

	if (ft_stacksize(*a) < 2)
		return ;
	na = *a;
	tmp = (*a)->next;
	na->next = tmp->next;
	tmp->next = na;
	*a = tmp;
	if (i == 1)
		write (1, "sa\n", 3);
}

void	sb(t_stack **b, int i)
{
	t_stack	*tmp;
	t_stack	*nb;

	if (ft_stacksize(*b) < 2)
		return ;
	nb = *b;
	tmp = (*b)->next;
	nb->next = tmp->next;
	tmp->next = nb;
	*b = tmp;
	if (i == 1)
		write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	write (1, "ss\n", 3);
}
