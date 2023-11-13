
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:10:21 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/01 16:27:00 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void print_stack(t_stack **stack) {

	t_stack *current;

	current = *stack;
	while (current)
	{
		ft_printf("value -> %d\n", current->value);
		ft_printf("mid -> %d\n", current->middle_value);
		ft_printf("chunk -> %d\n", current->chunk);
		current = current->next;
	}
}

void init_stack(t_stack **stack, char **args)
{
	int i;
	i = 0;

	while (args[i])
	{
		new_node(stack, ft_atoi(args[i]));
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	char **str;

	a = NULL;
	b = NULL;
	if (ac >= 3)
	{
		str = &av[1];
		if(is_valid_args(str))
		{
			init_stack(&a, str);
			print_stack(&a);
			if (ac <= 6)
				short_numbers(&a, &b);
//			else
//				large_numbers(&a, &b);
			move_numbers(&a, &b);
			ft_printf("------------------------------\n");
			print_stack(&a);
			ft_printf("------------------------------\n");
			print_stack(&b);
		}
		else
			ft_printf("invalid args\n");
	}
	else
		ft_printf("We have a problem\n");
	free_node(a);
	return(EXIT_OK);
}
