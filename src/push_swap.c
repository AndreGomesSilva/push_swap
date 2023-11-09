
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
		printf("%d\n", current->value);
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
	//t_stack *b;
	char **str;

	a = NULL;
	if (ac >= 3)
	{
		str = &av[1];
		if(is_valid_args(str))
		{
			long int z;

			z = ft_strtol(av[1], NULL, 10);
			printf("%ld\n", z);
			init_stack(&a, str);
			//ft_printf("%d\n", listlen(&a));
		}
		else
			ft_printf("invalid args\n");
	}
	else
		ft_printf("We have a problem\n");
	free_node(a);
	return(EXIT_OK);
}
