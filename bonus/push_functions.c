/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:11:48 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/31 12:07:25 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*na;
	t_stack	*nb;

	if (*a == NULL)
		return ;
	na = *a;
	nb = *b;
	*a = na->next;
	na->next = nb;
	*b = na;
}

void	pa(t_stack **b, t_stack **a)
{
	t_stack	*na;
	t_stack	*nb;

	if (*b == NULL)
		return ;
	nb = *b;
	na = *a;
	*b = nb->next;
	nb->next = na;
	*a = nb;
}
