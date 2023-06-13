/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:56:53 by twang             #+#    #+#             */
/*   Updated: 2023/06/13 17:50:56 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct timeval	int_to_timeval(int time_in_int)
{
	struct timeval	time_in_tv;

	time_in_tv.tv_usec = (time_in_int % 1000) * 1000;
	time_in_tv.tv_sec = (time_in_int / 1000);
	return (time_in_tv);
}

bool	timeval_is_inf(struct timeval a, struct timeval b)
{
	if (a.tv_sec < b.tv_sec)
		return (true);
	else if (a.tv_sec > b.tv_sec)
		return (false);
	else if (a.tv_usec < b.tv_usec)
		return (true);
	return (false);
}

struct timeval	substract_timeval(struct timeval a, struct timeval b)
{
	struct timeval	result;
	
	if (a.tv_usec >= b.tv_usec)
		result.tv_usec = a.tv_usec - b.tv_usec;
	else if (a.tv_usec < b.tv_usec)
	{
		a.tv_sec--;
		result.tv_usec = (a.tv_usec + 1000000) - b.tv_usec;
	}
	result.tv_sec = a.tv_sec - b.tv_sec;
	return (result);
}

int	display_routine(t_data *data, int id_philo, char *msg)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
	{
		printf("failed to get actual time\n");
		return(-1);
	}
	current = substract_timeval(current, data->time_to_start);
	printf("%03lu%03ld %d %s\n", current.tv_sec, current.tv_usec / 1000, id_philo, msg);
	return (0);
}
