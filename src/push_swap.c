/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:32:49 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/01/07 12:02:33 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node)
{
	if (a == NULL || b == NULL)
		return ;
	while (*b != cheapest_node && *a != cheapest_node->target_node)
		rr(a, b);
	set_current_position(*a, *b);
	set_above_medium(*a, *b);
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node)
{
	if (a == NULL || b == NULL)
		return ;
	while (*b != cheapest_node && *a != cheapest_node->target_node)
		rrr(a, b);
	set_current_position(*a, *b);
	set_above_medium(*a, *b);
}

void	finish_rotation(t_stack_node **stack, t_stack_node *best_node, char c)
{
	if (c == 'a')
	{
		while (*stack != best_node)
		{
			if (best_node->above_medium)
				ra(stack);
			else
				rra(stack);
		}
	}
	else if (c == 'b')
	{
		while (*stack != best_node)
		{
			if (best_node->above_medium)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_command(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest_node(*b);
	if (cheapest_node->above_medium && cheapest_node->target_node->above_medium)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_medium)
		&& !(cheapest_node->target_node->above_medium))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(a, cheapest_node->target_node, 'a');
	finish_rotation(b, cheapest_node, 'b');
	pa(a, b);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int				len_a;
	t_stack_node	*smallest_node;

	len_a = stack_length(a);
	while (len_a-- > 3)
		pb(b, a);
	mini_swap(a);
	while (*b != NULL)
	{
		init_nodes(*a, *b);
		move_command(a, b);
	}
	set_current_position(*a, *b);
	set_above_medium(*a, *b);
	smallest_node = find_smallest_node(*a);
	if (smallest_node->above_medium)
	{
		while (*a != smallest_node)
			ra(a);
	}
	else
	{
		while (*a != smallest_node)
			rra(a);
	}
}
