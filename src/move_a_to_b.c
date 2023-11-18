/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:47:51 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/17 14:47:54 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	finish_move_in_a(t_stack **a, int count_rotate, int chunk)
{
	t_stack	*first_a;

	first_a = *a;
	while (first_a != NULL && count_rotate--)
		reverse_rotate(a, "rra\n");
	first_a = *a;
	if (list_len_chunk(a, chunk) == 2)
		if (first_a->value > first_a->next->value)
			swap_node(a, "sa\n");
}

static void	move_smallest_chunk(t_stack **a, t_stack **b, int mid, int chunk)
{
	t_stack	*first_a;
	int		count_rotate;

	first_a = *a;
	count_rotate = 0;
	set_middle_chunk(a, chunk);
	mid = first_a->middle_value;
	while (remain_small_node(first_a, mid, chunk))
	{
		if (first_a->value < mid)
		{
			first_a->chunk += 1;
			push_to_stack(a, b, "pb\n");
		}
		else if (first_a->value >= mid)
		{
			rotate_list(a, "ra\n");
			count_rotate++;
		}
		else if (check_ascending_order(a, chunk))
			break ;
		first_a = *a;
	}
	finish_move_in_a(a, count_rotate, chunk);
}

void	move_a(t_stack **a, t_stack **b)
{
	t_stack	*first_a;
	int		target_chunk;
	int		mid;

	first_a = *a;
	target_chunk = first_a->chunk;
	set_middle_chunk(a, target_chunk);
	mid = first_a->middle_value;
	move_smallest_chunk(a, b, mid, target_chunk);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	while (!check_ascending_order_all(a))
		move_a(a, b);
}
