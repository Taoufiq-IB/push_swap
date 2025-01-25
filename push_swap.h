/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:23:25 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/25 16:50:58 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct t_stack
{
	int	index;
	int	position;
	int	value;

	struct t_stack *next;
}		s_stack;

char	**ft_split(char const *s, char c);
int		ft_atoi(char *nb);
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
char    *ft_strcat(char *dest, char *src);
void	ft_strcpy(char *dest, char *src);
void	free_split(char **split);


#endif