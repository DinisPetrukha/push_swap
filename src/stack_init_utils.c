/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 05:32:58 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/01/07 15:55:23 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *num)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (num[i] && (num[i] == ' ' || num[i] == '\t'
			|| num[i] == '\n' || num[i] == '\v'
			|| num[i] == '\f' || num[i] == '\r'))
		++i;
	if (num[i] == '+')
		++i;
	else if (num[i] == '-')
	{
		++i;
		sign *= -1;
	}
	while (num[i] && num[i] >= '0' && num[i] <= '9')
		result = result * 10 + (num[i++] - '0');
	return (result * sign);
}

int	check_syntax(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] && ((str[i] == ' ' || str[i] == '\t'
					|| str[i] == '\n' || str[i] == '\v'
					|| str[i] == '\f' || str[i] == '\r'
					|| str[i] == '-')
				|| (str[i] >= '0' && str[i] <= '9')))
			++i;
		else
			return (0);
	}
	return (1);
}

int	check_repetition(t_stack_node **a, int value)
{
	t_stack_node	*node;

	if (a == NULL)
		return (0);
	node = *a;
	while (node)
	{
		if (node->value == value)
			return (1);
		node = node->next;
	}
	return (0);
}

int	stack_length(t_stack_node **stack)
{
	int				i;
	t_stack_node	*current;

	if (stack == NULL)
		return (0);
	i = 0;
	current = *stack;
	while (current)
	{
		++i;
		current = current->next;
	}
	return (i);
}
