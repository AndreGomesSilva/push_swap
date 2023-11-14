//
// Created by angomes- on 11/13/23.
//

#include "../inc/push_swap.h"

static int		remain_chunk(t_stack **stack, int chunk)
{
	t_stack *lst;
	lst = *stack;

	while (lst)
	{
		if (lst->chunk == chunk)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}

static void sort_chunk(t_stack **a, t_stack **b)
{
	int mid;
	int target_chuck;
	int count_rotate;
	t_stack *first_node;

	first_node = *b;
	count_rotate = 0;
	target_chuck = first_node->chunk;
	mid = first_node->middle_value;
	while(check_chunk_great_node(first_node, mid, target_chuck))
	{
		if (first_node->chunk == target_chuck)
		{
			if (check_descending_order(b, target_chuck))
				while(remain_chunk(b, target_chuck) && first_node->chunk == target_chuck)
				{
					push_to_stack(b, a, "pa\n");
					first_node = *b;
				}
			if (first_node->value > mid)
			{
				push_to_stack(b, a, "pa\n");
				first_node = *b;
			}
			if (first_node->value <=  mid && check_chunk_great_node(first_node, mid, target_chuck))
			{
				rotate_list(b, "rb\n");
				first_node = *b;
				count_rotate++;
			}
		}
	}
	while (count_rotate--)
		reverse_rotate(b, "rrb\n");
}

void sort_great_chunk(t_stack **a, t_stack **b)
{
	t_stack *first_b;
	int 	great_chunk;

	first_b = *b;
	great_chunk = first_b->chunk;
	while(remain_chunk(b, great_chunk) && list_len_chunk(b, great_chunk) > 2)
	{
		set_middle_chunk(b, great_chunk);
		sort_chunk(a, b);
	}
}

void init_sort_chunk(t_stack **a, t_stack**b)
{
	t_stack *lst;

	lst = *b;
	if (list_len_chunk(b, lst->chunk) > 2)
		sort_great_chunk(a, b);
	else if (!check_descending_order(b, lst->chunk))
	{
		swap_node(b, "sb\n");
		push_to_stack(b, a, "pb\n");
		push_to_stack(b, a, "pb\n");
	}
	else if (check_descending_order(b, lst->chunk))
	{
		push_to_stack(b, a, "pb\n");
		push_to_stack(b, a, "pb\n");
	}
}