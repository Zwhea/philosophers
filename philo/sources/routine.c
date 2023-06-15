/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:38:24 by twang             #+#    #+#             */
/*   Updated: 2023/06/15 18:50:33 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_routine(t_philo *philo);

/*----------------------------------------------------------------------------*/

int	routine_philosophers(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(data->philo_maker));
	while (i < data->nb_of_philo)
	{
		if (pthread_create(&data->table[i].thread_id, NULL, (void *)_routine, \
								&(data->table[i])) != 0)
			return (return_error("thread create: failed", -4));
		i++;
	}
	if (gettimeofday(&data->time_to_start, NULL) == -1)
		return (return_error("get time of day: failed", -5));
	pthread_mutex_unlock(&(data->philo_maker));
	return (0);
}

static int	_routine(t_philo *philo)
{
	philo->is_dead = false;
	pthread_mutex_lock(&(philo->shared->philo_maker));
	pthread_mutex_unlock(&(philo->shared->philo_maker));
	philo->lifespan = philo->shared->time_to_die;
	if (philo->id % 2 != 0)
		usleep(1000);
	while (!(philo->is_dead))
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (0);
}
