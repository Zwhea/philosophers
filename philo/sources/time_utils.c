/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:56:53 by twang             #+#    #+#             */
/*   Updated: 2023/06/15 18:19:26 by twang            ###   ########.fr       */
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

struct timeval	add_timeval(struct timeval a, struct timeval b)
{
	struct timeval	result;

	result.tv_usec = a.tv_usec + b.tv_usec;
	if (result.tv_usec >= 1000000)
	{
		result.tv_sec++;
		result.tv_usec = result.tv_usec - 1000000;
	}
	result.tv_sec = a.tv_sec + b.tv_sec;
	return (result);
}

struct timeval	get_current_time(t_philo *philo)
{
	struct timeval current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		printf("failed to get current time\n");
	current_time = substract_timeval(current_time, philo->shared->time_to_start);
	return (current_time);
}
