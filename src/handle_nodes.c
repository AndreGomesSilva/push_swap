/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:38:26 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/04 11:44:29 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	listlen(t_stack **stack)
{
	int count;
	t_stack *current;

	count = 0;
	current = *stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_stack *last_node(t_stack *stack)
{
	t_stack *temp_node;

	temp_node = stack;
	while(stack->next != NULL)
	{
		temp_node = stack->next;
		stack = temp_node;
	}
	return (temp_node);
}

void new_node(t_stack **stack, int value)
{
  t_stack *node;
  t_stack *temp_node;

  node = (t_stack*) ft_calloc(1, sizeof(t_stack));
  if (!node)
    return ;
  node->next = NULL;
  node->value = value;
  if (*stack == NULL)
  {
    node->previous = NULL;
    *stack = node;
  }
  else
  {
	 temp_node = last_node(*stack);
	 temp_node->next = node;
	 node->previous = temp_node;
	 node->next = NULL;
  }
}