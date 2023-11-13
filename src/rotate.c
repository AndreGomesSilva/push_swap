//
// Created by angomes- on 11/7/23.
//

#include "../inc/push_swap.h"

void rotate_list(t_stack **stack, char *flag)
{
	t_stack *first_node;
	t_stack *next_node;
	t_stack *end_node;

	if(list_len(stack) < 3)
		return;
	first_node = *stack;
	next_node = first_node->next;
	end_node = last_node(*stack);
	end_node->next = first_node;
	first_node->previous = end_node;
	first_node->next = NULL;
	next_node->previous = NULL;
	*stack = next_node;
	ft_putstr_fd(flag, STDOUT_FILENO);
}