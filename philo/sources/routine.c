/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:38:24 by twang             #+#    #+#             */
/*   Updated: 2023/06/09 17:34:54 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*---- prototypes ------------------------------------------------------------*/

static void	_routine(t_data *data, int id_philo);

/*----------------------------------------------------------------------------*/

int	routine_philosophers(t_data *data)
{
	int	i;

	i = 1;
	while (i <= data->nb_of_philo)
	{
		printf("%d\n", i <= data->nb_of_philo);
		pthread_create(&data->table[i].thread_id, NULL, (void *)_routine, &(data->table[i]));
		i++;
	}
	return (0);
}

static void	_routine(t_data *data, int id_philo)
{
	(void)data;
	printf("je suis %d\n", data->table[id_philo].id);
	puts(YELLOW"ici"END);
}