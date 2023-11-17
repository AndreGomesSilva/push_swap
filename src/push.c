/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:48:11 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/17 14:48:12 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_to_stack(t_stack **src, t_stack **dest, char *flag)
{
	t_stack	*first_src;
	t_stack	*first_dest;
	t_stack	*next_src;

	if (!src || !*src)
		return ;
	first_src = *src;
	first_dest = *dest;
	next_src = first_src->next;
	if (next_src)
		next_src->previous = NULL;
	*src = next_src;
	if (!*dest)
	{
		*dest = first_src;
		first_src->next = NULL;
	}
	else
	{
		first_src->next = first_dest;
		*dest = first_src;
		first_dest->previous = first_src;
	}
	ft_putstr_fd(flag, STDOUT_FILENO);
}
