//
// Created by silva on 12/11/2023.
//

#include "../inc/push_swap.h"

static int	check_node_small(t_stack *stack, int check, int chunk)
{
	t_stack *lst;

	lst = stack;
	while (lst)
	{
		if (lst->value < check && lst->chunk == chunk)
			return (TRUE);
		lst = lst->next;
	}
	return(FALSE);
}

void	zero_chunk(t_stack **stack)
{
	t_stack *lst;

	lst = *stack;
	while(lst)
	{
		lst->chunk = 0;
		lst = lst->next;
	}
}

void	mark_chunk(t_stack **stack)
{
	t_stack *lst;
	int 	great_c;

	lst = *stack;
	great_c = 0;
	while (lst)
	{
		if (lst->chunk > great_c)
			great_c = lst->chunk;
		lst = lst->next;
	}
	lst = *stack;
	while (lst)
	{
		if(!lst->chunk)
			lst->chunk = great_c + 1;
		lst = lst->next;
	}
}

static void move_the_smallest(t_stack **a, t_stack **b, int chunk)
{
	int mid;
	t_stack *first_node;
	t_stack *end_node;

	first_node = *a;
	mid = first_node->middle_value;
	end_node = last_node(first_node);
	while(check_node_small(first_node, mid, chunk))
	{
		while (first_node->value < mid)
		{
			push_to_stack(a, b, "pb\n");
			first_node = *a;
		}
		while (end_node->value < mid)
		{
			reverse_rotate(a, "rra\n");
			push_to_stack(a, b, "pb\n");
			end_node = last_node(first_node);
		}
		if(first_node->value >= mid && check_node_small(first_node, mid, chunk))
		{
			rotate_list(a, "ra\n");
			first_node = *a;
		}
	}
}

//void finish(t_stack **a, t_stack **b)
//{
//	t_stack *first_node;
//	t_stack *second_node;
//
//	first_node = *b;
//	second_node = first_node->next;
//	if (first_node->value < second_node->value)
//	{
//		swap_node(b, "sb\n");
//		push_to_stack(b, a, "pa\n");
//		push_to_stack(b, a, "pa\n");
//	}
//	else
//	{
//		push_to_stack(b, a, "pa\n");
//		push_to_stack(b, a, "pa\n");
//	}
//}

void move_numbers(t_stack **a,t_stack **b)
{
	while (list_len(a) > 3)
	{
		set_middle_value(a);
		move_the_smallest(a, b, 0);
		mark_chunk(b);
	}
	short_numbers(a);
	while (list_len(b))
	{
		if (check_ascending_order_all(a))
			move_b_to_a(a, b);
		if (!check_ascending_order_all(a))
		{
			move_a_to_b(a, b);
			zero_chunk(a);
		}
	}
//	if (list_len(b) == 2)
//		finish(a, b);
}
