/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:20:43 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/31 12:07:07 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	find_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*p;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*p;

	i = 0;
	while (str[i])
		i++;
	p = malloc(i + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
