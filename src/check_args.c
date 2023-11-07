//
// Created by angomes- on 11/4/23.
//

#include "../inc/push_swap.h"

static int number_is_equal(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (atoi(str[i]) == atoi(str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int args_is_digits(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int is_valid_args(char **str)
{
	if (args_is_digits(str))
	{
		if (!number_is_equal(str))
		{
			return (1);
		}
	}
	return (0);
}