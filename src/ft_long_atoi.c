//
// Created by angomes- on 11/11/23.
//

#include "../inc/push_swap.h"

long int ft_long_atoi(char *str)
{
	long number;
	int sign;
	int i;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			number = (number * 10) + str[i] - '0';
		i++;
	}

	return (number * sign);
}