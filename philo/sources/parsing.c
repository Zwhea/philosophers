/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:48:36 by twang             #+#    #+#             */
/*   Updated: 2023/06/07 16:27:56 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_arguments(t_data *data, char **av)
{
	data->nb_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[6])
		data->must_eat = ft_atoi(av[5]);
	if (data->nb_of_philo <= 0 || data->time_to_die <= 0 || data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		print_error("wrong format for argument, please think before testing");
	return (0);
}