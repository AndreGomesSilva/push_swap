/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:47:15 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/17 14:47:30 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	set_value_to_lst(t_stack **stack, int mid)
{
	t_stack	*lst;

	lst = *stack;
	while (lst)
	{
		lst->middle_value = mid;
		lst = lst->next;
	}
}

static void	sort_array(t_stack **stack, int *array, int len)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < len)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
		i++;
	}
	set_value_to_lst(stack, array[len / 2]);
}

static void	fill_array(t_stack **stack, int *array, int len)
{
	t_stack	*lst;
	int		i;

	lst = *stack;
	i = 0;
	while (i < len && lst)
	{
		array[i] = lst->value;
		lst = lst->next;
		i++;
	}
}

void	set_middle_value(t_stack **stack)
{
	int	*array;
	int	len;

	len = list_len(stack);
	array = ft_calloc(len, sizeof(int));
	fill_array(stack, array, len);
	sort_array(stack, array, len);
	free(array);
}
