/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:38:24 by twang             #+#    #+#             */
/*   Updated: 2023/06/09 16:12:28 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_routine(t_data *data);

/*----------------------------------------------------------------------------*/

int	routine_philosophers(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_of_philo)
	{
		if (pthread_create(&data->table[i].thread_id, NULL, (void *)_routine, &(data->table[i])) != 0)
			return(printf("Couldn't bring forth the thread\n"), -1);
	}
	return (0);
}

static void	_routine(t_data *data)
{
	(void)data;
	puts(YELLOW"ici"END);
}