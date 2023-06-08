/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:45:46 by twang             #+#    #+#             */
/*   Updated: 2023/06/08 10:57:06 by twang            ###   ########.fr       */
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
			init_philosophers(&data);
	}
	else
		print_error("wrong number of arguments");
	return (0);
}
