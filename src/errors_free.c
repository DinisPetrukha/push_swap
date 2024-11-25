/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:25:08 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/01/07 17:27:48 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_free(t_stack_node **a, char **argv, int argc)
{
	int				i;
	t_stack_node	*next_node;
	t_stack_node	*current;

	i = 1;
	if (argc)
	{
		if (argv[0][0] == '\0')
			free(argv[0]);
		while (argv[i])
		{
			if (argv[i])
				free(argv[i++]);
		}
		free(argv);
	}
	current = *a;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	error_output();
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	error_output(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
