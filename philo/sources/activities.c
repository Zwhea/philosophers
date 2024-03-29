/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:01:27 by twang             #+#    #+#             */
/*   Updated: 2023/06/21 11:42:46 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo, pthread_mutex_t *mutex, int *fork)
{
	int	winner;

	winner = 0;
	(void)mutex;
	pthread_mutex_lock(mutex);
	if (*fork == 0)
	{
		*fork = philo->id;
		winner = philo->id;
		pthread_mutex_lock(&(philo->shared->whistleblower));
		if (display_routine(philo->shared, philo->id, "has taken a fork") != 0)
			return (return_error("display_routine: failed", -5));
		pthread_mutex_unlock(&(philo->shared->whistleblower));
	}
	winner = *fork;
	pthread_mutex_unlock(mutex);
	return (winner);
}

void	give_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->m_left_fork));
	philo->left_fork = 0;
	pthread_mutex_unlock(&(philo->m_left_fork));
	pthread_mutex_lock(philo->m_right_fork);
	*philo->right_fork = 0;
	pthread_mutex_unlock(philo->m_right_fork);
}

void	eaten_all_meals(t_philo *philo)
{
	philo->meal++;
	pthread_mutex_lock(&(philo->shared->watchman));
	if (philo->meal >= philo->shared->must_eat && philo->meal != -1)
	{
		philo->shared->philo_is_full++;
		philo->meal = -1;
	}
	if (philo->shared->philo_is_full == philo->shared->nb_of_philo)
		philo->shared->the_end = true;
	pthread_mutex_unlock(&(philo->shared->watchman));
}

bool	is_he_dead(t_philo *philo)
{
	if (timeval_is_inf(get_current_time(philo), philo->lifespan) == false)
	{
		philo->is_dead = true;
		pthread_mutex_lock(&(philo->shared->whistleblower));
		if (display_routine(philo->shared, philo->id, "died") != 0)
		{
			printf("display_routine: failed\n");
			return (true);
		}
		pthread_mutex_unlock(&(philo->shared->whistleblower));
		pthread_mutex_lock(&(philo->shared->watchman));
		philo->shared->the_end = true;
		pthread_mutex_unlock(&(philo->shared->watchman));
		return (true);
	}
	return (false);
}
