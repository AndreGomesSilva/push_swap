//
// Created by angomes- on 11/7/23.
//

#include "../inc/push_swap.h"

void swap_node(t_stack **stack)
{
	t_stack *second_node;
	t_stack *first_node;
	t_stack *next_node;

	first_node = *stack;
	second_node = first_node->next;
	next_node = second_node->next;
	second_node->previus = NULL;
	second_node->next = first_node;
	first_node->next = next_node;
	next_node->previus = first_node;
	first_node->previus = second_node;
	*stack = second_node;
}