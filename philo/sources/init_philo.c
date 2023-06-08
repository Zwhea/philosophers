/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:05:22 by twang             #+#    #+#             */
/*   Updated: 2023/06/08 15:59:58 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_alloc_memory(t_data *data);
static int	_init_mutex(t_data *data);

/*----------------------------------------------------------------------------*/

static int	_alloc_memory(t_data *data)
{
	data->table = (t_philo *)malloc(data->nb_of_philo) * sizeof(t_philo);
	if (!data->table)
		return (-1);
	return (0);
}

static int	_init_mutex(t_data *data)
{
	int	i;
	
	i = -1;
	pthread_mutex_init(&(data->m_write), NULL);
	pthread_mutex_lock(&(data->m_write));
	while (++i < data->nb_of_philo)
		launch_one_philo(data, i);
	pthread_mutex_unlock(&(data->m_write));
}

int	init_philosophers(t_data *data)
{
	if (_alloc_memory(data) != 0)
		return (-1);
	if (_init_mutex != 0)
		return (-1);
	return (0);
}
