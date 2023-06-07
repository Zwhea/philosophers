/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:21:51 by wangthea          #+#    #+#             */
/*   Updated: 2023/06/07 15:20:14 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	long int		result;

	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
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
