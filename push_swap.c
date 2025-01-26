/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:33:55 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/26 17:09:57 by tibarike         ###   ########.fr       */
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
		return (NULL);
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

int	*int_array(int argc, char **argv, int *size)
{
	char	*arr;
	int		*int_arr;
	char	**split;
	int		i;

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
		int_arr[i] = ft_atoi(split[i]);
		i++;
	}
	free_split(split);
	*size = i;
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
	int size;

	if (argc == 1)
		return (1);
	size = 0;
	int *arr = int_array(argc, argv, &size);
	if (arr == NULL)
		return(1);
	is_dup(arr, size);
	free(arr);
}