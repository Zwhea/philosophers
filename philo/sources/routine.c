/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:38:24 by twang             #+#    #+#             */
/*   Updated: 2023/06/13 18:15:12 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_routine(t_philo *philo);

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
		{
			perror("pthread_create: error");
			return (-1);
		}
		i++;
	}
	if (gettimeofday(&data->time_to_start, NULL) == -1)
	{
		printf("failed to get starting time\n");
		return (-1);
	}
	pthread_mutex_unlock(&(data->philo_maker));
	return (0);
}

static void	_routine(t_philo *philo)
{
	pthread_mutex_lock(&(philo->shared->philo_maker));
	pthread_mutex_unlock(&(philo->shared->philo_maker));
	pthread_mutex_lock(&(philo->shared->whistleblower));
	while (philo->shared->the_end == false)
	{
		if (display_routine(philo->shared, philo->id, "is thinking") != 0)
			printf("error of display");
		if (gettimeofday(&philo->shared->time_to_start, NULL) == -1)
			printf("failed to get update starting time\n");
		if (timeval_is_inf(philo->shared->time_to_die, philo->shared->time_to_start) == false)
			philo->shared->the_end = true;
	}
	pthread_mutex_unlock(&(philo->shared->whistleblower));
}
