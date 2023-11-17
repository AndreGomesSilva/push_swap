/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:19:28 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/17 14:47:33 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	free_node(t_stack *head)
{
	t_stack	*temp_node;

	if (head)
	{
		while (head)
		{
			temp_node = head->next;
			free(head);
			head = temp_node;
		}
		return (TRUE);
	}
	else
		return (FALSE);
}
