/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:33:55 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/27 17:28:44 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_arguments(int argc, char **argv, char sep)
{
	char	*joined;
	int		len;
	int		i;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len += ft_strlen(argv[i]) + 1;
		i++;
	}
	joined = malloc(len * sizeof(char));
	if (!joined)
		return (free(joined), NULL);
	joined[0] = '\0';
	i = 1;
	while (i < argc)
	{
		ft_strcat(joined, argv[i]);
		if (i < argc -1)
           ft_strcat(joined, (char[]){sep, '\0'});
		i++;
	}
	return (joined);
}

int	*init_array(int argc, char **argv, int *size)
{
	char	*arr;
	int		*int_arr;
	char	**split;
	int		i;
	int		success;

	i = 0;
	arr = join_arguments(argc, argv, ' ');
	if (!arr)
		(write(2, "Error\n", 6), exit(1));
	split = ft_split(arr, ' ');
	free(arr);
	while (split[i])
		i++;
	int_arr = malloc(i * sizeof(int));
	if (!int_arr)
		return (free_split(split), NULL);
	i = 0;
	while (split[i])
	{
		int_arr[i] = ft_atoi(split[i], &success);
		if (!success)
		{
			free(int_arr);
			free_split(split);
			(write(2, "Error\n", 6), exit(1));
		}
		i++;
	}
	*size = i;
	free_split(split);
	return (int_arr);
}


void	create_stack(s_stack **a, int *int_arr, int size)
{
	int		i;
	int		value;
	s_stack	*new_stack;
	
	i = 0;
	value = 0;
	while (i < size)
	{
		new_stack =ft_stacknew(int_arr[i], 0);
		ft_stackadd_back(a, new_stack);
		i++;
	}
}

#include <stdio.h>
int main(int argc, char **argv)
{
	int		size;
	s_stack *a = NULL;
	s_stack *b = NULL;
	int		stack_size;

	stack_size = 0;
	size = 0;
	int *arr = init_array(argc, argv, &size);
	if (arr == NULL)
		return(1);
	is_dup(arr, size);
	create_stack(&a, arr, size);
	free(arr);
	if (check_sorted(a) == 0)
	{
		if (ft_stacksize(a) <= 5)
			sort_five_less(&a, &b);
	}
	ft_stackclear(&a);
	return (0);
}

	// tmp = a;
	// while (tmp)
	// {
	// 	printf ("%d->", tmp->value);
	// 	tmp = tmp->next;
	// }