/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:31:34 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/01/07 17:02:51 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_smallest_node(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	set_target_node(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match;

	while (stack_b)
	{
		current_a = stack_a;
		best_match = LONG_MAX;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match)
			{
				best_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			stack_b->target_node = find_smallest_node(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	set_current_position(t_stack_node *a, t_stack_node *b)
{
	int	i;

	i = 0;
	while (a)
	{
		a->current_position = i++;
		a = a->next;
	}
	i = 0;
	while (b)
	{
		b->current_position = i++;
		b = b->next;
	}
}

void	set_above_medium(t_stack_node *a, t_stack_node *b)
{
	int	length_a;
	int	length_b;

	length_a = stack_length(&a);
	length_b = stack_length(&b);
	while (a)
	{
		if (a->current_position > (length_a / 2))
			a->above_medium = false;
		else
			a->above_medium = true;
		a = a->next;
	}
	while (b)
	{
		if (b->current_position > (length_b / 2))
			b->above_medium = false;
		else
			b->above_medium = true;
		b = b->next;
	}
}

void	set_push_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_length(&a);
	len_b = stack_length(&b);
	while (b)
	{
		if (!(b->above_medium))
			b->push_price = len_b - b->current_position;
		else
			b->push_price = b->current_position;
		if (!(b->target_node->above_medium))
			b->push_price += len_a - (b->target_node->current_position);
		else
			b->push_price += b->target_node->current_position;
		b = b->next;
	}
}
