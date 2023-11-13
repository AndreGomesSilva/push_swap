//
// Created by silva on 13/11/2023.
//

#include "../inc/push_swap.h"

int 	check_ascending_order(t_stack **a, int chunk)
{
	t_stack *lst;
	t_stack *next_node;
	int 	current_value;

	lst = *a;
	while(lst)
	{
		while (lst->chunk == chunk && lst->next != NULL)
		{
			next_node = lst->next;
			current_value = lst->value;
			if (current_value > next_node->value && next_node->chunk == chunk)
				return (FALSE);
			lst = lst ->next;
		}
		if(lst != NULL)
			lst = lst->next;
	}
	return (TRUE);
}

int 	check_descending_order(t_stack **b, int chunk)
{
	t_stack *lst;
	t_stack *next_node;
	int 	current_value;

	lst = *b;
	while(lst)
	{
		while (lst->chunk == chunk && lst->next != NULL)
		{
			next_node = lst->next;
			current_value = lst->value;
			if (current_value < next_node->value && next_node->chunk == chunk)
				return (FALSE);
			lst = lst ->next;
		}
		if(lst != NULL)
			lst = lst->next;
	}
	return (TRUE);
}
