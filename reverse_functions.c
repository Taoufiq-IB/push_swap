/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:20:53 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/26 18:00:39 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(s_stack **a, int i)
{
	s_stack	*na;
	s_stack	*tmp;

	na = *a;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = na;
	*a = tmp->next;
	tmp->next = NULL;
	if (i == 1)
		write (1, "rra\n", 4);
}
void	rrb(s_stack **b, int i)
{
	s_stack	*nb;
	s_stack	*tmp;

	if (ft_stacksize(b) < 2)
		return ;

	nb = *b;
	tmp = *b;

	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = nb;
	*b = tmp->next;
	tmp->next = NULL;
	if (i == 1)
		write (1, "rrb\n", 4);
}

void	rrr(s_stack	**a, s_stack **b)
{
	rra(a, 0);
	rra(b, 0);
	write (1, "rrr\n", 4);
}