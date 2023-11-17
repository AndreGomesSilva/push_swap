//
// Created by angomes- on 11/13/23.
//

#include "../inc/push_swap.h"

void move_a(t_stack **a, t_stack **b)
{
	t_stack *first_a;
	int 	target_chunk;
	int 	count_rotate;
	int 	mid;

	first_a = *a;
	count_rotate = 0;
	target_chunk = first_a->chunk;
	set_middle_chunk(a, target_chunk);
	mid = first_a->middle_value;
	while (remain_small_node(first_a, mid, target_chunk))
		{
			if (first_a->value < mid)
				push_to_stack(a, b, "pb\n");
			else if (first_a->value >=  mid)
			{
				rotate_list(a, "ra\n");
				count_rotate++;
			}
			first_a = *a;
		}
	while(first_a != NULL && count_rotate--)
		reverse_rotate(a, "rra\n");
	if (list_len_chunk(a, target_chunk) == 2)
	{
		first_a = *a;
		if (first_a->value > first_a->next->value)
			swap_node(a, "sa\n");
	}
}


void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack *first_node;
	int chunk;

	first_node = *a;
	chunk = first_node->chunk;
	while (!check_ascending_order_all(a) && list_len_chunk(a, chunk) != 2)
		move_a(a, b);
}