/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:54:18 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/25 18:07:58 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_stack	*ft_stacknew(int value, int index)
{
	s_stack	*tmp;

	tmp = malloc(sizeof(s_stack));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->index = index;
	tmp->next = NULL;
	return (tmp);
}
