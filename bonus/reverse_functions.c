/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:20:53 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/31 12:07:30 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stack **a)
{
	t_stack	*na;
	t_stack	*tmp;

	if (ft_stacksize(*a) < 2)
		return ;
	na = *a;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = na;
	*a = tmp->next;
	tmp->next = NULL;
}

void	rrb(t_stack **b)
{
	t_stack	*nb;
	t_stack	*tmp;

	if (ft_stacksize(*b) < 2)
		return ;
	nb = *b;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = nb;
	*b = tmp->next;
	tmp->next = NULL;
}

void	rrr(t_stack	**a, t_stack **b)
{
	rra(a);
	rra(b);
}
