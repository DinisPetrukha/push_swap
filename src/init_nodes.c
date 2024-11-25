/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:40:01 by dpetrukh          #+#    #+#             */
/*   Updated: 2023/12/31 14:44:09 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_stack_node *b)
{
	t_stack_node	*current;
	int				price;

	if (b == NULL)
		return ;
	price = INT_MAX;
	while (b)
	{
		b->cheapest = false;
		if (b->push_price < price)
		{
			price = b->push_price;
			current = b;
		}
		b = b->next;
	}
	current->cheapest = true;
}

t_stack_node	*find_cheapest_node(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;

	if (stack == NULL)
		return (NULL);
	cheapest_node = NULL;
	while (stack)
	{
		if (stack->cheapest)
			cheapest_node = stack;
		stack = stack->next;
	}
	return (cheapest_node);
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_target_node(a, b);
	set_current_position(a, b);
	set_above_medium(a, b);
	set_push_price(a, b);
	set_cheapest(b);
}
