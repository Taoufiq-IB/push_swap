/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibarike <tibarike@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:09:38 by tibarike          #+#    #+#             */
/*   Updated: 2025/01/31 15:30:28 by tibarike         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	p_error(char *line, char *joined_ops, t_stack **a)
{
	free(line);
	free(joined_ops);
	line = get_next_line(-1);
	free(line);
	ft_stackclear(a);
	(write(2, "Error\n", 6), exit(1));
}

static void	check_operation(char *line, char *joined_ops, t_stack **a)
{
	if (ft_strcmp(line, "sa\n") == 0)
		return ;
	else if (ft_strcmp(line, "sb\n") == 0)
		return ;
	else if (ft_strcmp(line, "ss\n") == 0)
		return ;
	else if (ft_strcmp(line, "ra\n") == 0)
		return ;
	else if (ft_strcmp(line, "rb\n") == 0)
		return ;
	else if (ft_strcmp(line, "rr\n") == 0)
		return ;
	else if (ft_strcmp(line, "rra\n") == 0)
		return ;
	else if (ft_strcmp(line, "rrb\n") == 0)
		return ;
	else if (ft_strcmp(line, "rrr\n") == 0)
		return ;
	else if (ft_strcmp(line, "pa\n") == 0)
		return ;
	else if (ft_strcmp(line, "pb\n") == 0)
		return ;
	else
		p_error(line, joined_ops, a);
}

char	*read_operations(t_stack **a)
{
	char	*joined_ops;
	char	*line;

	joined_ops = NULL;
	line = get_next_line(0);
	while (line != NULL)
	{
		check_operation(line, joined_ops, a);
		joined_ops = ft_strjoin(joined_ops, line);
		free(line);
		line = get_next_line(0);
	}
	return (joined_ops);
}

void	apply_operations(char *joined_ops, t_stack **a, t_stack **b)
{
	char	**ops;
	int		i;

	i = 0;
	ops = ft_split(joined_ops, '\n');
	free(joined_ops);
	while (ops[i])
	{
		operations(ops[i], a, b);
		free(ops[i]);
		i++;
	}
	free(ops);
}
