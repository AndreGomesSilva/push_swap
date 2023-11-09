//
// Created by angomes- on 11/9/23.
//
#include "../inc/push_swap.h"

long int ft_strtol(char *str, char **endptr, int base)
{
	long int result;
	int sign;
	int digit;

	result = 0;
	sign = 1;
	digit = 0;
	if (base < 2 || base > 36)
	{
		if (endptr != NULL)
			*endptr = (char*) str;
		return (0);
	}

	while (*str == ' ' || *str == '\t' || *str == '\r')
		str++;

	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			digit = *str - '0';
		else if (*str >= 'a' && *str <= 'z')
			digit = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'Z')
			digit = *str - 'A' + 10;
		else
			break;
		if (digit >= base)
			break;
		result = result * base + digit;
		str++;
	}

	if (endptr != NULL)
		*endptr = (char*)str;
	return(result *sign);
}