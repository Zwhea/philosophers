/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:01:27 by twang             #+#    #+#             */
/*   Updated: 2023/06/14 13:22:53 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define is_searching_for_forks 1

/*---- prototypes ------------------------------------------------------------*/

static int	searching_forks(t_philo *philo);

/*----------------------------------------------------------------------------*/

void	thinking(t_philo *philo)
{
	if (display_routine(philo->shared, philo->id, "is thinking") != 0)
		printf("error of display");
	while (is_searching_for_forks)
	{
		if (searching_forks(philo) != 0)
			break ;
	}
	return ;
	if (gettimeofday(&philo->shared->time_to_start, NULL) == -1)
		printf("failed to get update starting time\n");
	if (timeval_is_inf(philo->shared->time_to_die, philo->shared->time_to_start) == false)
		philo->shared->the_end = true;
}

void	eating(t_philo *philo)
{
	if (display_routine(philo->shared, philo->id, "is eating") != 0)
		printf("error of display");
}

void	sleeping(t_philo *philo)
{
	if (display_routine(philo->shared, philo->id, "is thinking") != 0)
		printf("error of display");
}

static int	searching_forks(t_philo *philo)
{
	puts("je cherche");
	return (0);
}