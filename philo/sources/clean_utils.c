/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:06:11 by twang             #+#    #+#             */
/*   Updated: 2023/06/09 14:15:48 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_destroyer(t_data *data)
{
	int	philo_id;

	philo_id = 0;
	pthread_mutex_destroy(&(data->whistleblower));
	while (philo_id <= data->nb_of_philo)
	{
		pthread_mutex_destroy(&(data->table[philo_id].m_left_fork));
	}
}
