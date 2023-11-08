//
// Created by angomes- on 11/7/23.
//

#include "../inc/push_swap.h"

void rotate_list(t_stack **stack)
{
	t_stack *first_node;
	t_stack *next_node;
	t_stack *end_node;

	if(!*stack)
		return ;
	first_node = *stack;
	next_node = first_node->next;
	end_node = last_node(*stack);
	end_node->next = first_node;
	first_node->previus = end_node;
	first_node->next = NULL;
	next_node->previus = NULL;
	*stack = next_node;
}