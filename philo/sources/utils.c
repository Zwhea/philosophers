/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:21:51 by wangthea          #+#    #+#             */
/*   Updated: 2023/06/12 14:23:47 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	long int		result;

	result = 0;
	if (!str)
		return (-1);
	if (*str == 43 || *str == 45)
		return (-1);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			result = (result * 10) + *str++ - '0';
			if (result > 2147483647)
				return (-1);
		}
		else
			return (-1);
	}
	return ((int)(result));
}

static void	*ft_memset(void *dst, int c, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		*(unsigned char *)(dst + i) = (unsigned char)c;
		i++;
	}
	return (dst);
}

void	ft_bzero(void *dst, size_t n)
{
	ft_memset(dst, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	if (size > 0 && count > (SIZE_MAX / size))
		return (NULL);
	array = malloc(count * size);
	if (!array)
		return (NULL);
	ft_bzero(array, count * size);
	return (array);
}
