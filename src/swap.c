//
// Created by angomes- on 11/7/23.
//

#include "../inc/push_swap.h"

void swap_node(t_stack **stack, char *flag)
{
	t_stack *second_node;
	t_stack *first_node;
	t_stack *next_node;

	first_node = *stack;
	second_node = first_node->next;
	next_node = second_node->next;
	second_node->previous = NULL;
	second_node->next = first_node;
	if (next_node)
	{
		first_node->next = next_node;
		next_node->previous = first_node;
	}
	else
		first_node->next = NULL;
	first_node->previous = second_node;
	*stack = second_node;
	ft_putstr_fd(flag, STDOUT_FILENO);
}