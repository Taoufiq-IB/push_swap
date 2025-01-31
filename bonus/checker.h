/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:23:25 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/31 15:19:36 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
void	check_spaces(char **argv, int *arr);

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

//------------------------checker_utils-------------------------

char	*read_operations(t_stack **a);
void	apply_operations(char *joined_ops, t_stack **a, t_stack **b);
int		ft_strcmp(char *str1, char *str2);
int		handle_no_operations(t_stack *a);
void	checks(char **argv, int *arr, int size);

//-------------------------operations---------------------------

void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **b, t_stack **a);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack	**a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	operations(char *op, t_stack **a, t_stack **b);

//------------------------get_next_line--------------------------

char	*ft_strdup(char *str);
int		find_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);

#endif