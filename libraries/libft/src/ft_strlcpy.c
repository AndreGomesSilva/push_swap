/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angomes- <angomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:21:09 by angomes-          #+#    #+#             */
/*   Updated: 2023/05/22 16:53:30 by angomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{	
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (*(src + i) && --size)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (len);
}
