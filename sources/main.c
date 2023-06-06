/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:45:46 by twang             #+#    #+#             */
/*   Updated: 2023/06/06 13:04:37 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define NC	"\e[0m"

#include "philo.h"

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		puts("ici");
		// if (parse_arguments(ac, av) == SUCCESS)
		// 	init_philosophers();
	}
	else 
	{
		printf(RED"philo: wrong number of arguments\n"END);
		printf(GREEN"philo: usage: ./philo [number_of_philosophers]");
		printf(" [time_to_die] [time_to_eat] [time_to_sleep]");
		printf(" [number_of_times_each_philosopher_must_eat]\n"END);
	}
	return (0);
}
