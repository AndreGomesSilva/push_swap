//
// Created by angomes- on 11/7/23.
//

#include "../inc/push_swap.h"

void push_to_stack(t_stack **src, t_stack **dest, char *flag)
{
	t_stack *first_src;
	t_stack *first_dest;
	t_stack  *next_src;

	if(!*src)
		return ;
	first_src = *src;
	first_dest = *dest;
	next_src = first_src->next;
	if (next_src)
		next_src->previous = NULL;
	*src = next_src;
	if (!*dest) {
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