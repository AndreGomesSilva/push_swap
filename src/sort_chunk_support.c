/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_support.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:48:55 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/17 14:52:16 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	list_len_chunk(t_stack **stack, int chunk)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = *stack;
	while (current)
	{
		if (current->chunk == chunk)
			count++;
		current = current->next;
	}
	return (count);
}

int	remain_great_node(t_stack *stack, int check, int chunk)
{
	t_stack	*lst;

	lst = stack;
	while (lst)
	{
		if (lst->chunk == chunk && lst->value > check)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}

int	remain_small_node(t_stack *stack, int check, int chunk)
{
	t_stack	*lst;

	lst = stack;
	while (lst)
	{
		if (lst->chunk == chunk && lst->value < check)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}
