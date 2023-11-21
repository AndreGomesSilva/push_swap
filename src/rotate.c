/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:48:48 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/17 14:48:51 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_list(t_stack **stack, char *flag)
{
	t_stack	*first_node;
	t_stack	*next_node;
	t_stack	*end_node;

	if (list_len(stack) < 3)
		return ;
	first_node = *stack;
	next_node = first_node->next;
	end_node = last_node(*stack);
	end_node->next = first_node;
	first_node->previous = end_node;
	first_node->next = NULL;
	next_node->previous = NULL;
	*stack = next_node;
	ft_putstr_fd(flag, 1);
}
