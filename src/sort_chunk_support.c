//
// Created by angomes- on 11/13/23.
//
#include "../inc/push_swap.h"

int	list_len_chunk(t_stack **stack, int chunk)
{
	int count;
	t_stack *current;

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

int	check_chunk_great_node(t_stack *stack, int check, int chunk)
{
	t_stack *lst;

	lst = stack;
	while (lst)
	{
		if (lst->chunk == chunk && lst->value > check)
			return (TRUE);
		lst = lst->next;
	}
	return(FALSE);
}