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

void move_numbers(t_stack **a,t_stack **b)
{
	int great_chunk_a;
	t_stack *first_node;

	first_node = *a;
	great_chunk_a = first_node->chunk;
	while (list_len(a) > 3)
	{
		set_middle_value(a);
		move_the_smallest(a, b, 0);
		mark_chunk(b);
	}
	short_numbers(a);
	init_sort_chunk(a, b);
	init_sort_chunk(a, b);
	init_sort_chunk(a, b);

}
