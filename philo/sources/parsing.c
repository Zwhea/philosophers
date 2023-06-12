/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:48:36 by twang             #+#    #+#             */
/*   Updated: 2023/06/12 18:12:35 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_arguments(t_data *data, int ac, char **av)
{
	data->nb_of_philo = ft_atoi(av[1]);
	data->time_to_die = ((ft_atoi(av[2]) % 1000) * 1000);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (data->nb_of_philo <= 0 || data->time_to_die <= 0 \
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
	{
		print_error("wrong format, please think before testing");
		return (-1);
	}
	if (ac == 6)
	{
		data->must_eat = ft_atoi(av[5]);
		if (data->must_eat <= 0)
			return (print_error("wrong format, please think before testing"), \
						-1);
	}
	if (data->time_to_die <= 60 || data->time_to_eat <= 60 \
		|| data->time_to_sleep <= 60)
	{
		printf(YELLOW"philo: warning: "END);
		printf("the program might not run correctly with those values.\n");
	}
	printf("%ld && %ld\n", time.tv_sec, time.tv_usec);
	return (0);
}
