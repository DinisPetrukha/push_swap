/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:23:01 by dpetrukh          #+#    #+#             */
/*   Updated: 2023/12/31 14:42:40 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stack_node **stack_a)
{
	int				num;
	t_stack_node	*current;

	if (stack_a == NULL)
		return (0);
	current = *stack_a;
	num = current->value;
	while (current)
	{
		if (num > current->value)
			return (0);
		num = current->value;
		current = current->next;
	}
	return (1);
}

int	find_min(t_stack_node *stack)
{
	int				num;
	t_stack_node	*current;

	if (stack == NULL)
		return (0);
	current = stack;
	num = current->value;
	while (current)
	{
		if (current->value < num)
			num = current->value;
		current = current->next;
	}
	return (num);
}

int	find_max(t_stack_node *stack)
{
	int				num;
	t_stack_node	*current;

	if (stack == NULL)
		return (0);
	current = stack;
	num = current->value;
	while (current)
	{
		if (current->value > num)
			num = current->value;
		current = current->next;
	}
	return (num);
}

void	mini_swap(t_stack_node **a)
{
	if (!check_order(a))
	{
		if (find_min(*a) == (*a)->value)
		{
			sa(a);
			ra(a);
		}
		else if (find_max(*a) == (*a)->value)
		{
			ra(a);
			if (!check_order(a))
				sa(a);
		}
		else
		{
			if ((*a)->next->value == find_max(*a))
				rra(a);
			else
				sa(a);
		}
	}
}
