/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:33:55 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/25 18:16:07 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_arguments(int argc, char **argv)
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
	i = 1;
	while (i < argc)
	{
		ft_strcat(joined, argv[i]);
		if (i < argc -1)
			ft_strcat(joined, " ");
		i++;
	}
	return (joined);
}

int	*int_array(int argc, char **argv)
{
	char	*arr;
	int		*int_arr;
	char	**split;
	int		i;

	i = 0;
	arr = join_arguments(argc, argv);
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
	return (int_arr);
}

void	create_stack(s_stack **a, int *int_arr)
{
	int	i;
	
	i = 0;
	while (int_arr[i])
	{
		if ()
	}
}

#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
}