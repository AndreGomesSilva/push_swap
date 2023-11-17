/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:47:58 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/17 14:48:06 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_b(t_stack **a, t_stack **b)
{
	t_stack	*first_b;
	int		target_chunk;
	int		count_rotate;
	int		mid;

	first_b = *b;
	count_rotate = 0;
	target_chunk = first_b->chunk;
	set_middle_chunk(b, target_chunk);
	mid = first_b->middle_value;
	while (first_b != NULL && remain_great_node(first_b, mid, target_chunk)
		&& list_len_chunk(b, target_chunk) > 2)
	{
		if (first_b->value > mid)
			push_to_stack(b, a, "pa\n");
		else if (first_b->value <= mid)
		{
			rotate_list(b, "rb\n");
			count_rotate++;
		}
		first_b = *b;
	}
	while (first_b != NULL && count_rotate--)
		reverse_rotate(b, "rrb\n");
	if (list_len_chunk(b, target_chunk) == 2)
	{
		first_b = *b;
		if (first_b->value < first_b->next->value)
			swap_node(b, "sb\n");
		push_to_stack(b, a, "pa\n");
		push_to_stack(b, a, "pa\n");
	}
	else if (list_len_chunk(b, target_chunk) == 1)
		push_to_stack(b, a, "pa\n");
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	if (check_ascending_order_all(a))
		if (list_len(b))
			move_b(a, b);
}
