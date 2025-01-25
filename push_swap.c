/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:33:55 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/25 09:54:48 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split);
		i++;
	}
	free(split);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while ((str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

char    *ft_strcat(char *dest, char *src)
{
	int     i;
	int     j;	
	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
	    i++;
	}
	while (src[j] != '\0')
	{
	    dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_strcpy(char *dest, char *src)
{
	unsigned int	j;

	j = 0;
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
}

char	*join_arguments(int argc, char **argv, char sep)
{
	char	*joined;
	int		len;
	int		i;

	i = 1;
	while (i < argc)
	{
		len += ft_strlen(argv[i] + 1);
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

int is_dup(char **argv)
{
	int	i;
	int	j;


	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	int		i = 1;
	char	*arr;
	int		j = 0;
	int		*int_arr;
	char	**split;
	
	if (argc == 1)
		return (1);
	if(is_dup(argv) == 0)
		(write (2, "Error\n", 6), exit(1));
	arr = join_arguments(argc, argv, ' ');
	printf("%s", arr);
	if (!arr)
	{
		(write(2, "Error\n", 6), exit(1));
	}
	split = ft_split(arr, ' ');
	while (split[j])
		printf ("%s", split[j++]);
// 	free(arr);
// 	while (split[j])
// 		j++;
// 	int_arr = malloc(j * sizeof(int));
// 	if (!int_arr)
// 	{
// 		free(int_arr);
// 		(write(2, "Error\n", 6), exit(1));
// 	}
// 	j = 0;
// 	while (split[j])
// 	{
// 		int_arr[j] = ft_atoi(split[j]);
// 		free(split[j]);
// 		j++;
// 	}
// 	j = 0;
// }
