/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:08:06 by dpetrukh          #+#    #+#             */
/*   Updated: 2023/12/31 14:34:07 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (stack == NULL || *stack == NULL)
		return ;
	last_node = find_last_node((*stack));
	(*stack)->prev = last_node;
	last_node->next = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	write(1, "ra\n", 3);
	rotate(a);
}

void	rb(t_stack_node **b)
{
	write(1, "rb\n", 3);
	rotate(b);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}
