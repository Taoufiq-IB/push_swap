/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:39:50 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/25 19:23:41 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(s_stack **lst, s_stack *new)
{
	s_stack	*last_n;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_n = ft_lstlast(*lst);
	last_n->next = new;
}

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

int	ft_stacksize(s_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	ft_stackclear(s_stack **lst, void (*del)(void *))
{
	s_stack	*crnt;
	s_stack	*tmp;

	if (!lst || !del)
		return ;
	crnt = *lst;
	while (crnt != NULL)
	{
		tmp = crnt;
		crnt = crnt->next;
		del(tmp->value);
		del(tmp->position);
		del(tmp->index);
		free(tmp);
	}
	*lst = NULL;
}


s_stack	get_max(s_stack	*stack)
{
	s_stack	*current;
	s_stack	*tmp;

	current = stack;
	tmp = current;
	while (current)
	{
		if (current->value > tmp->value)
			tmp = current;
		current = current->next;
	}
	return(*tmp);
}

s_stack	get_min(s_stack	*stack)
{
	s_stack	*current;
	s_stack	*tmp;

	current = stack;
	tmp = current;
	while (current)
	{
		if (current->value < tmp->value)
			tmp = current;
		current = current->next;
	}
	return(*tmp);
}

int check_sorted(s_stack *stack)
{
	s_stack *tmp;
	
	tmp = stack;
	while (tmp)
	{
		if (tmp->next != NULL)
		{
			if (tmp->value > tmp->next->value)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}