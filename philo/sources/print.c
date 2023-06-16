/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:23:12 by twang             #+#    #+#             */
/*   Updated: 2023/06/16 17:28:10 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *msg, int return_val)
{
	printf(RED"philo: - invalid argument: "END);
	printf("%s\n", msg);
	printf(RED"       - usage: "END);
	printf("./philo [number_of_philosophers]");
	printf(" [time_to_die] [time_to_eat] [time_to_sleep]");
	printf(" *[number_of_times_each_philosopher_must_eat]\n");
	return (return_val);
}

int	return_error(char *msg, int return_val)
{
	printf("philo: %s\n", msg);
	return (return_val);
}

int	display_routine(t_data *data, int id_philo, char *msg)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
		return_error("get time of day: failed", -5);
	current = substract_timeval(current, data->time_to_start);
	printf("%03lu%03ld %d %s\n", current.tv_sec, current.tv_usec / 1000, \
																id_philo, msg);
	return (0);
}
