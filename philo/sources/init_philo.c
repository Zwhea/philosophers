/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:05:22 by twang             #+#    #+#             */
/*   Updated: 2023/06/15 17:07:50 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_init_mutex(t_data *data);
static int	_create_philo(t_data *data);
static void	_init_table_struct(t_data *data, int ph_id);
static int	_init_mutex_philo(t_data *data, int ph_id);

/*----------------------------------------------------------------------------*/

int	init_philosophers(t_data *data)
{
	data->table = (t_philo *)ft_calloc(data->nb_of_philo, sizeof(t_philo));
	if (!data->table)
		return (return_error("ft_calloc: table of philos", -1));
	if (_init_mutex(data) != 0)
	{
		free(data->table);
		return (return_error("_init_mutex: failed", -2));
	}
	if (_create_philo(data) != 0)
	{
		free(data->table);
		mutex_destroyer(data);
		return (return_error("_create_philo: failed", -2));
	}
	return (0);
}

static int	_init_mutex(t_data *data)
{
	if (pthread_mutex_init(&(data->philo_maker), NULL) != 0)
		return (return_error("mutex_init: failed philo_maker init", -3));
	if (pthread_mutex_init(&(data->whistleblower), NULL) != 0)
		return (return_error("mutex_init: failed whistleblower init", -3));
	return (0);
}

static int	_create_philo(t_data *data)
{
	int	ph_id;

	ph_id = -1;
	while (++ph_id < data->nb_of_philo)
	{
		_init_table_struct(data, ph_id);
		if (_init_mutex_philo(data, ph_id) != 0)
			return (-3);
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

static int	_init_mutex_philo(t_data *data, int ph_id)
{
	if (pthread_mutex_init(&(data->table[ph_id].m_left_fork), NULL) != 0)
	{
		while (--ph_id > -1)
			pthread_mutex_destroy(&(data->table[ph_id].m_left_fork));
		return (return_error("mutex_init: failed forks init", -3));
	}
	return (0);
}
