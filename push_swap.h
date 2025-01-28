/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:23:25 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/28 17:36:17 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				index;
	int				position;
	int				value;

	struct s_stack	*next;
}		t_stack;

//---------------------------utils------------------------------

char	**ft_split(char const *s, char c);
int		ft_atoi(char *nb, int *success);
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
void	free_split(char **split);
void	is_dup(int *arr, int size);
void	check_spaces(char **argv);

//-------------------------stack_utils--------------------------

int		check_sorted(t_stack *stack);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stacknew(int value, int index);
int		ft_stacksize(t_stack *lst);
void	ft_stackclear(t_stack **lst);
t_stack	*get_max(t_stack *stack);
t_stack	*get_min(t_stack *stack);
void	give_position(t_stack *b);
int		get_max_element_position(t_stack *stack);

//-------------------------operations---------------------------

void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	rra(t_stack **a, int i);
void	rrb(t_stack **b, int i);
void	rrr(t_stack	**a, t_stack **b);
void	ra(t_stack **a, int i);
void	rb(t_stack **b, int i);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack **a, int i);
void	sb(t_stack **b, int i);
void	ss(t_stack **a, t_stack **b);

//-------------------------sorting-------------------------------

void	sort_five_less(t_stack **a, t_stack **b);
void	sort3(t_stack **a);
void	sort4(t_stack **a, t_stack **b);
void	sort5(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);

#endif