/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:16:36 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/31 12:07:41 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack **a)
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
}

void	sb(t_stack **b)
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
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
