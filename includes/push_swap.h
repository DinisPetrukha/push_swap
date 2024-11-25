/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:38:35 by dpetrukh          #+#    #+#             */
/*   Updated: 2024/01/07 15:45:02 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	long				value;
	int					current_position;
	int					push_price;
	bool				above_medium;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
}	t_stack_node;

//FT_SPLIT
int				count_words(char *str, char separator);
char			*get_next_word(char *str, char separator);
char			**ft_split(char *argv, char separator);

//ERROR FREE MEMORY
void			error_free(t_stack_node **a, char **argv, int argc);
void			free_stack(t_stack_node **stack);
void			free_argv(char **argv);
void			error_output(void);

//STACK_INIT
t_stack_node	*find_last_node(t_stack_node *node);
void			append_node(t_stack_node **a, int value);
int				stack_init(t_stack_node **a, char **argv, int argc);

//STACK_INIT_UTILS
long			ft_atol(char *num);
int				check_syntax(char *str);
int				check_repetition(t_stack_node **a, int value);
int				stack_length(t_stack_node **stack);

//SWAP
void			swap(t_stack_node **stack);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

//PUSH
void			push(t_stack_node **dest, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

//ROTATE
void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

//REVERSE_ROTATE
void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

//MINI SWAP
int				check_order(t_stack_node **stack_a);
int				find_min(t_stack_node *stack);
int				find_max(t_stack_node *stack);
void			mini_swap(t_stack_node **a);

//SET_NODE
t_stack_node	*find_smallest_node(t_stack_node *stack);
void			set_target_node(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_current_position(t_stack_node *a, t_stack_node *b);
void			set_above_medium(t_stack_node *a, t_stack_node *b);
void			set_push_price(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
void			init_nodes(t_stack_node *a, t_stack_node *b);

//PUSH_SWAP
t_stack_node	*find_cheapest_node(t_stack_node *stack);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			reverse_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			finish_rotation(t_stack_node **stack, t_stack_node *best_node,
					char c);
void			move_command(t_stack_node **a, t_stack_node **b);
void			push_swap(t_stack_node **a, t_stack_node **b);

#endif