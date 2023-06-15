/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:01:03 by twang             #+#    #+#             */
/*   Updated: 2023/06/15 16:36:27 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_wait_for_philo(t_data *data, int philo_id);

/*----------------------------------------------------------------------------*/

int	end_of_life(t_data *data)
{
	int	philo_id;

	philo_id = 0;
	while (philo_id < data->nb_of_philo)
	{
		if (_wait_for_philo(data, philo_id) != 0)
			return (-1);
		philo_id++;
	}
	if (mutex_destroyer(data) != 0)
		return (-1);
	free(data->table);
	return (0);
}

static int	_wait_for_philo(t_data *data, int philo_id)
{
	if (data->table[philo_id].thread_id)
	{
		if (pthread_join(data->table[philo_id].thread_id, NULL) != 0)
		{
			printf("pthread_join: error\n");
			return (-1);
		}
	}
	return (0);
}

int	mutex_destroyer(t_data *data)
{
	int	philo_id;

	philo_id = 0;
	pthread_mutex_destroy(&(data->whistleblower));
	while (philo_id < data->nb_of_philo)
	{
		if (pthread_mutex_destroy(&(data->table[philo_id].m_left_fork)) != 0)
		{
			printf("pthread_mutext_destroy: error\n");
			return (-1);
		}
		philo_id++;
	}
	return (0);
}
