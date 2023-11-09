//
// Created by angomes- on 11/8/23.
//

#include "../inc/push_swap.h"

void reverse_rotate(t_stack	**stack)
{
	t_stack  *first_node;
	t_stack  *end_node;
	t_stack  *previous_node;

	first_node = *stack;
	end_node = last_node(*stack);
	previous_node = end_node->previous;
	first_node->previous = end_node;
	end_node->next = first_node;
	end_node->previous = NULL;
	previous_node->next = NULL;
	*stack = end_node;
}