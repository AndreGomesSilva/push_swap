/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:49:09 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/17 14:49:12 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	bigger_node(t_stack *first_node, t_stack *second_node)
{
	if (first_node->value > second_node->value)
		return (TRUE);
	else
		return (FALSE);
}

static void	tiny_sort(t_stack **a, t_stack *top, t_stack *next, t_stack *third)
{
	if (bigger_node(top, next)
		&& bigger_node(third, top))
		swap_node(a, "sa\n");
	else if (bigger_node(top, next) && bigger_node(next, third))
	{
		swap_node(a, "sa\n");
		reverse_rotate(a, "rra\n");
	}
	else if (bigger_node(top, next) && bigger_node(top, third))
		rotate_list(a, "ra\n");
	else if (bigger_node(next, third) && bigger_node(third, top))
	{
		swap_node(a, "sa\n");
		rotate_list(a, "ra\n");
	}
	else if (bigger_node(next, top) && bigger_node(top, third))
		reverse_rotate(a, "rra\n");
}

static void	simple_sort_a(t_stack **a)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*third_node;

	first_node = *a;
	second_node = first_node->next;
	third_node = second_node->next;
	if (list_len(a) < 2)
		return ;
	if (list_len(a) == 2 && bigger_node(first_node, second_node))
		swap_node(a, "sa\n");
	else if (list_len(a) == 3)
		tiny_sort(a, first_node, second_node, third_node);
}

void	short_numbers(t_stack **a)
{
	int	len;

	len = list_len(a);
	if (len < 4)
		simple_sort_a(a);
}
