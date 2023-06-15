/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:45:46 by twang             #+#    #+#             */
/*   Updated: 2023/06/15 17:11:21 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		ft_bzero((void *)&data, sizeof(t_data));
		if (parse_arguments(&data, ac, av) == 0)
		{
			if (init_philosophers(&data) != 0)
				return (-1);
			if (routine_philosophers(&data) != 0)
				return (-1);
			if (end_of_life(&data) != 0)
				return (-1);
		}
	}
	else
		return (print_error("wrong number of arguments", -1));
	return (0);
}
