/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:23:25 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/27 17:30:48 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef struct t_stack
{
	int	index;
	int	position;
	int	value;

	struct t_stack *next;
}		s_stack;

//---------------------------utils------------------------------

char	**ft_split(char const *s, char c);
int		ft_atoi(char *nb, int *success);
int		ft_strlen(char *str);
char    *ft_strcat(char *dest, char *src);
void	free_split(char **split);
void	is_dup(int *arr, int size);

//-------------------------stack_utils--------------------------

int		check_sorted(s_stack *stack);
void	ft_stackadd_back(s_stack **lst, s_stack *new);
s_stack	*ft_stacknew(int value, int index);
int		ft_stacksize(s_stack *lst);
void	ft_stackclear(s_stack **lst);
s_stack	*ft_stacklast(s_stack *stack);
s_stack	*get_max(s_stack *stack);
s_stack	*get_min(s_stack *stack);

//-------------------------operations---------------------------

void	pb(s_stack **a, s_stack **b);
void	pa(s_stack **a, s_stack **b);
void	rra(s_stack **a, int i);
void	rrb(s_stack **b, int i);
void	rrr(s_stack	**a, s_stack **b);
void	ra(s_stack **a, int i);
void	rb(s_stack **b, int i);
void	rr(s_stack **a, s_stack **b);
void	sa(s_stack **a, int i);
void	sa(s_stack **b, int i);
void	ss(s_stack **a, s_stack **b);

//-------------------------sorting-------------------------------

void	sort_five_less(s_stack **a, s_stack **b);
void	sort3(s_stack **a);
void	sort4(s_stack **a, s_stack **b);
void	sort5(s_stack **a, s_stack **b);

#endif