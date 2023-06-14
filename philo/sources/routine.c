/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:38:24 by twang             #+#    #+#             */
/*   Updated: 2023/06/14 13:06:52 by twang            ###   ########.fr       */
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
	thinking(philo);
	eating(philo);
	sleeping(philo);
	pthread_mutex_unlock(&(philo->shared->whistleblower));
}
