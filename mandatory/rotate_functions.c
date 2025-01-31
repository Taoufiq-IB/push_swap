/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:00:53 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/28 14:40:29 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int i)
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
	if (i == 1)
		write (1, "ra\n", 3);
}

void	rb(t_stack **b, int i)
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
	if (i == 1)
		write (1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write (1, "rr\n", 3);
}
