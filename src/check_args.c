/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:16:39 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/17 14:47:46 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_limits(char **str)
{
	long int	number;
	int			i;

	i = 0;
	number = 0;
	while (str[i])
	{
		number = ft_strtol(str[i], NULL, 10);
		if (number > LIMIT_MAX_INT || number < LIMIT_MIN_INT)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	number_is_equal(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

static int	args_is_digits(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (((str[i][j] == '-') || (str[i][j]) == '+')
				&& (!ft_isdigit(str[i][j + 1])))
				return (FALSE);
			if (str[i][j] == '-' && j != 0)
				return (FALSE);
			if ((!ft_isdigit(str[i][j])
				&& ((str[i][j] != '-') && (str[i][j] != '+'))))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	is_valid_args(char **str)
{
	if (check_limits(str) && args_is_digits(str))
		if (!number_is_equal(str))
			return (TRUE);
	return (FALSE);
}
