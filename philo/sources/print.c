/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:23:12 by twang             #+#    #+#             */
/*   Updated: 2023/06/07 15:36:00 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *msg)
{
	printf(RED"philo: - invalid argument: "END);
	printf("%s\n", msg);
	printf(RED"       - usage: "END);
	printf("./philo [number_of_philosophers]");
	printf(" [time_to_die] [time_to_eat] [time_to_sleep]");
	printf(" *[number_of_times_each_philosopher_must_eat]\n");
}