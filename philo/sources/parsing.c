/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:48:36 by twang             #+#    #+#             */
/*   Updated: 2023/06/19 16:48:26 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_arguments(t_data *data, int ac, char **av)
{
	data->nb_of_philo = ft_atoi(av[1]);
	data->time_to_die = int_to_timeval(ft_atoi(av[2]));
	data->time_to_eat = int_to_timeval(ft_atoi(av[3]));
	data->time_to_sleep = int_to_timeval(ft_atoi(av[4]));
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0 \
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (print_error("wrong format, please think", -1));
	if (ac == 6)
	{
		data->must_eat = ft_atoi(av[5]);
		if (data->must_eat <= 0)
			return (print_error("wrong format, please think", -1));
	}
	else if (ac == 5)
		data->must_eat = -1;
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 \
		|| ft_atoi(av[4]) < 60)
	{
		printf(YELLOW"philo: warning: "END);
		printf("the program might not run correctly with those values.\n");
	}
	return (0);
}
