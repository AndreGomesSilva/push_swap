/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:48:40 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/17 14:48:45 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate(t_stack	**stack, char *flag)
{
	t_stack	*first_node;
	t_stack	*end_node;
	t_stack	*previous_node;

	first_node = *stack;
	end_node = last_node(*stack);
	previous_node = end_node->previous;
	first_node->previous = end_node;
	end_node->next = first_node;
	end_node->previous = NULL;
	previous_node->next = NULL;
	*stack = end_node;
	ft_putstr_fd(flag, STDOUT_FILENO);
}
