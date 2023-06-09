/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:05:22 by twang             #+#    #+#             */
/*   Updated: 2023/06/09 15:32:45 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_init_mutex(t_data *data);
static int	_create_philo(t_data *data);
static void	_init_table_struct(t_data *data, int ph_id);
static int	_init_mutex_philo(t_philo *table, int ph_id);

/*----------------------------------------------------------------------------*/

int	init_philosophers(t_data *data)
{
	data->table = (t_philo *)ft_calloc(data->nb_of_philo + 1, sizeof(t_philo));
	if (!data->table)
	{
		perror("malloc: table of philos");
		return (-1);
	}
	if (_init_mutex(data) != 0)
	{
		free(data->table);
		return (-2);
	}
	pthread_mutex_lock(&(data->whistleblower));
	if (_create_philo(data) != 0)
	{
		free(data->table);
		mutex_destroyer(data);
		return (-2);
	}
	pthread_mutex_unlock(&(data->whistleblower));
	return (0);
}

static int	_init_mutex(t_data *data)
{
	if (pthread_mutex_init(&(data->whistleblower), NULL) != 0)
	{
		perror("mutex_init: whistleblower init");
		return (-2);
	}
	return (0);
}

static int	_create_philo(t_data *data)
{
	int	ph_id;

	ph_id = -1;
	while (++ph_id < data->nb_of_philo)
	{
		_init_table_struct(data, ph_id);
		if (_init_mutex_philo(data->table, ph_id) != 0)
			return (-2);
	}
	return (0);
}

static void	_init_table_struct(t_data *data, int ph_id)
{
	data->table[ph_id].id = ph_id + 1;
	data->table[ph_id].shared = data;
	if (ph_id == data->nb_of_philo - 1)
	{
		data->table[ph_id].m_right_fork = &(data->table[0].m_left_fork);
		data->table[ph_id].right_fork = &(data->table[0].left_fork);
	}
	else
	{
		data->table[ph_id].m_right_fork = &(data->table[ph_id + 1].m_left_fork);
		data->table[ph_id].right_fork = &(data->table[ph_id + 1].left_fork);
	}
}

static int	_init_mutex_philo(t_philo *table, int ph_id)
{
	if (pthread_mutex_init(&(table[ph_id].m_left_fork), NULL) != 0)
	{
		perror("mutex_init: philo init");
		while (--ph_id >= -1)
			pthread_mutex_destroy(&(table[ph_id].m_left_fork));
		return (-2);
	}
	return (0);
}
