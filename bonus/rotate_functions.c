/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:00:53 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/31 12:07:33 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack **a)
{
	t_stack	*na;
	t_stack	*tmp;

	if (ft_stacksize(*a) < 2)
		return ;
	na = *a;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	*a = na->next;
	na->next = NULL;
	tmp->next = na;
}

void	rb(t_stack **b)
{
	t_stack	*nb;
	t_stack	*tmp;

	if (ft_stacksize(*b) < 2)
		return ;
	nb = *b;
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	*b = nb->next;
	nb->next = NULL;
	tmp->next = nb;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
