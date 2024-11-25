/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:45:20 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/01/07 11:52:32 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node;

	if (src == NULL || *src == NULL)
		return ;
	node = (*src);
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if ((*dest) == NULL)
	{
		(*dest) = node;
		(*dest)->next = NULL;
	}
	else
	{
		(*dest)->prev = node;
		node->next = (*dest);
		(*dest) = node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	write(1, "pa\n", 3);
	push(a, b);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	write(1, "pb\n", 3);
	push(b, a);
}
