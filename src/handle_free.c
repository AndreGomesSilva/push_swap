//
// Created by angomes- on 11/7/23.
//

#include "../inc/push_swap.h"

int free_node(t_stack *head) {
	t_stack *temp_node;

	if (head)
	{
		while(head)
		{
			temp_node = head->next;
			free(head);
			head = temp_node;
		}
		return(1);
	}
	else
		return (0);
}