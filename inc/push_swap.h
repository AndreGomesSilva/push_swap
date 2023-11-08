/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:25:10 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/01 16:22:21 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define EXIT_OK 0
# define EXIT_FAIL 1
# define ERROR (-1)

# include "../libraries/libft/inc/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int		value;
	struct s_stack	*next;
	struct s_stack	*previus;
}			t_stack;


int is_valid_args(char **str);
void new_node(t_stack **stack, int value);
t_stack *last_node(t_stack *stack);
int free_node(t_stack *head);
void swap_node(t_stack **stack);
void rotate_list(t_stack **stack);
void push_to_stack(t_stack **src, t_stack **dest);
int	listlen(t_stack **stack);

#endif
