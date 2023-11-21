/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:48:23 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/17 14:48:36 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	init_stack(t_stack **stack, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		new_node(stack, ft_atoi(args[i]));
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**str;

	a = NULL;
	b = NULL;
	if (ac >= 3)
	{
		str = &av[1];
		if (is_valid_args(str))
		{
			init_stack(&a, str);
			if (ac <= 4 && !check_ascending_order_all(&a))
				short_numbers(&a);
			else if (!check_ascending_order_all(&a))
				move_numbers(&a, &b);
		}
		else
			write(2, "Error\n", 6);
		free_node(a);
	}
	else if (av[1])
		if (av[1][0] == '\0' || !is_valid_args(&av[1]))
			write(2, "Error\n", 6);
	return (EXIT_OK);
}
