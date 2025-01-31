/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:33:55 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/31 15:16:57 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*join_arguments(int argc, char **argv, char sep)
{
	char	*joined;
	int		len;
	int		i;

	i = 1;
	len = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			(write(2, "Error\n", 6), exit(1));
		len += ft_strlen(argv[i++]) + 1;
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
			ft_strcat(joined, (char []){sep, '\0'});
		i++;
	}
	return (joined);
}

static char	**create_split(int argc, char **argv)
{
	int		i;
	char	*arr;
	char	**split;

	i = 0;
	arr = join_arguments(argc, argv, ' ');
	if (!arr)
		(write(2, "Error\n", 6), exit(1));
	split = ft_split(arr, ' ');
	while (split[i])
	{
		if (!split[i])
			(write(2, "Error\n", 6), exit(1));
		i++;
	}
	free(arr);
	return (split);
}

static int	*init_array(int argc, char **argv, int *size, int i)
{
	int		*int_arr;
	char	**split;
	int		success;

	i = 0;
	split = create_split(argc, argv);
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
	return (free_split(split), int_arr);
}

static	void	create_stack(t_stack **a, int *int_arr, int size)
{
	int		i;
	t_stack	*new_stack;

	i = 0;
	while (i < size)
	{
		new_stack = ft_stacknew(int_arr[i], 0);
		ft_stackadd_back(a, new_stack);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		size;
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	char	*joined_ops;

	if (argc <= 1)
		return (0);
	size = 0;
	a = NULL;
	b = NULL;
	arr = init_array(argc, argv, &size, 0);
	if (!arr)
		exit (1);
	checks(argv, arr, size);
	(create_stack(&a, arr, size), free(arr));
	joined_ops = read_operations(&a);
	if (!joined_ops)
		return (handle_no_operations(a));
	apply_operations(joined_ops, &a, &b);
	if (a && check_sorted(a) == 1 && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	(ft_stackclear(&a), ft_stackclear(&b));
}
