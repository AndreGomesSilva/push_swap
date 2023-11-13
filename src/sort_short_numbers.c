//
// Created by angomes- on 11/11/23.
//
#include "../inc/push_swap.h"
static int bigger_node(t_stack *first_node, t_stack *second_node)
{
	if (first_node->value > second_node->value)
		return (TRUE);
	else
		return (FALSE);
}
static void simple_sort(t_stack **a)
{
	t_stack *first_node;
	t_stack *second_node;
	t_stack *third_node;

	first_node = *a;
	if (list_len(a) < 3)
		return ;
	second_node = first_node->next;
	third_node = second_node->next;
	if (bigger_node(first_node, second_node) && bigger_node(third_node, first_node))
		swap_node(a, "sa\n");
	else if (bigger_node(first_node, second_node) && bigger_node(second_node, third_node))
	{
		swap_node(a, "sa\n");
		reverse_rotate(a, "rra\n");
	}
	else if (bigger_node(first_node, second_node) && bigger_node(first_node, third_node))
		rotate_list(a, "ra\n");
	else if (bigger_node(second_node, third_node) && bigger_node(third_node, first_node))
	{
		swap_node(a, "sa\n");
		rotate_list(a, "ra\n");
	}
	else if (bigger_node(second_node, first_node) && bigger_node(first_node, third_node))
		reverse_rotate(a, "rra\n");
}

void five_sort(t_stack **a, t_stack **b)
{
	push_to_stack(a, b, "pb\n");
	push_to_stack(a, b, "pb\n");
	simple_sort(a);
	push_to_stack(b, a, "pa\n");
	simple_sort(a);
	push_to_stack(b, a, "pa\n");
	simple_sort(a);
}

void short_numbers(t_stack **a, t_stack **b)
{
	int len;

	len = list_len(a);
	if (len == 3)
		simple_sort(a);
	else if(len <= 5)
		five_sort(a, b);
}