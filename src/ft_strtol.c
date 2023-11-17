/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:19:07 by angomes-          #+#    #+#             */
/*   Updated: 2023/11/17 14:47:34 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long int	convert_base(char *str, int base)
{
	int			digit;
	long int	result;

	digit = 0;
	result = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			digit = *str - '0';
		else if (*str >= 'a' && *str <= 'z')
			digit = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'Z')
			digit = *str - 'A' + 10;
		else
			break ;
		if (digit >= base)
			break ;
		result = result * base + digit;
		str++;
	}
	return (result);
}

long int	ft_strtol(char *str, char **endptr, int base)
{
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	if (base < 2 || base > 36)
	{
		if (endptr != NULL)
			*endptr = (char *) str;
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
	result = convert_base(str, base);
	if (endptr != NULL)
		*endptr = (char *)str;
	return (result * sign);
}
