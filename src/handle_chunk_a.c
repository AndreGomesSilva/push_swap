//
// Created by angomes- on 11/14/23.
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

void move_chunk_a_to_b(t_stack **a, t_stack **b)
{
	t_stack *first_node;
	int		target_chunk;
	int		mid;
	int		count_rotate;

	first_node = *a;
	count_rotate = 0;
	target_chunk = first_node->chunk;
	set_middle_chunk(a, target_chunk);
	mid = first_node->middle_value;
	while (check_node_small(first_node, mid, target_chunk) && !check_ascending_order(a, target_chunk))
	{
		if (first_node->value < mid)
		{
			push_to_stack(a, b, "pb\n");
			first_node = *a;
		}
		else if (first_node->next->value < mid && first_node->next->chunk == target_chunk)
		{
			swap_node(a, "sa\n");
			push_to_stack(a, b, "pb\n");
			first_node = *a;
		}
		else if (first_node->value >= mid && check_node_small(first_node,mid, target_chunk))
		{
			rotate_list(a, "ra\n");
			first_node = *a;
			count_rotate++;
		}
	}
	while(count_rotate--)
		reverse_rotate(a, "rra\n");
}

void init_sort_chunk_a(t_stack **a, t_stack **b)
{
	t_stack *lst;

	lst = *a;
	while (!check_ascending_order(a, lst->chunk))
	{
		if (list_len_chunk(a, lst->chunk) < 3)
		{
			swap_node(a, "sa\n");
		}
		else
		{
			move_chunk_a_to_b(a, b);
		}
	}
}
