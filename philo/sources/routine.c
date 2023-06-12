/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:38:24 by twang             #+#    #+#             */
/*   Updated: 2023/06/12 18:12:16 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_routine(t_data *data);

/*----------------------------------------------------------------------------*/

int	routine_philosophers(t_data *data)
{
	int	i;

	i = 0;
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
		return (-1);
	return (0);
}

void	_routine(t_data *data)
{

	/*
	( ms % 1000 )* 1000;
	je ne sais pas quoi faire :
		- je crois qu'il faut que je recupere le time of the day avec gettimeofday
		- je les fais penser;
	*/
	puts(YELLOW"ici"END);
}
