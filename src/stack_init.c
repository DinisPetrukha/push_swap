/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 04:02:43 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/01/08 11:36:28 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *node)
{
	if (node == NULL)
		return (node);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	append_node(t_stack_node **a, int value)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->value = value;
	node->next = NULL;
	if (*a == NULL)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*a);
		node->prev = last_node;
		last_node->next = node;
	}
}

int	stack_init(t_stack_node **a, char **argv, int argc)
{
	int		i;
	long	value;

	i = 0;
	value = 0;
	while (argv[i])
	{
		if (!check_syntax(argv[i]))
			error_free(a, argv - 1, argc);
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			error_free(a, argv - 1, argc);
		if (check_repetition(a, (int)value))
			error_free(a, argv - 1, argc);
		append_node(a, (int)value);
		++i;
	}
	if (argc)
		free_argv(argv);
	return (1);
}
