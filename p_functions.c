/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:11:48 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/26 19:24:52 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(s_stack **a, s_stack **b)
{
	s_stack	*na;
	s_stack	*nb;

	if (*a == NULL)
		return ;
	na = *a;
	nb = *b;
	*a = na->next;
	na->next = nb;
	*b = na;
	write (1, "pb\n", 3);
}

void	pa(s_stack **a, s_stack **b)
{
	s_stack	*na;
	s_stack *nb;

	if (*b == NULL)
		return ;
	nb = *b;
	na = *a;

	*b = nb->next;
	nb->next = na;
	*a = nb;
	write (1, "pa\n", 3);
}
