/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:01:27 by twang             #+#    #+#             */
/*   Updated: 2023/06/15 18:56:18 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_take_fork(t_philo *philo, pthread_mutex_t mutex, int *fork);
static void	_give_fork(t_philo *philo);

/*----------------------------------------------------------------------------*/

void	thinking(t_philo *philo)
{
	int	left;
	int	right;

	left = 0;
	right = 0;
	pthread_mutex_lock(&(philo->shared->whistleblower));
	if (display_routine(philo->shared, philo->id, "is thinking") != 0)
	{
		printf("display_routine: failed\n");
		return ;
	}
	pthread_mutex_unlock(&(philo->shared->whistleblower));
	while (philo->id != left && philo->id != right)
	{
		left = _take_fork(philo, philo->m_left_fork, &(philo->left_fork));
		right = _take_fork(philo, *philo->m_right_fork, philo->right_fork);
	}
}

void	eating(t_philo *philo)
{
	philo->start_meal = get_current_time(philo);
	philo->end_meal = add_timeval(philo->start_meal, \
												philo->shared->time_to_eat);
	philo->lifespan = add_timeval(philo->start_meal, \
												philo->shared->time_to_die);
	pthread_mutex_lock(&(philo->shared->whistleblower));
	if (display_routine(philo->shared, philo->id, "is eating") != 0)
	{
		printf("display_routine: failed\n");
		return ;
	}
	pthread_mutex_unlock(&(philo->shared->whistleblower));
	while (timeval_is_inf(get_current_time(philo), philo->end_meal) != false)
	{
		if (philo->is_dead == true)
			return ;
	}
	_give_fork(philo);
	if (philo->shared->must_eat > 0)
		philo->shared->must_eat--;
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&(philo->shared->whistleblower));
	if (display_routine(philo->shared, philo->id, "is sleeping") != 0)
	{
		printf("display_routine: failed\n");
		return ;
	}
	pthread_mutex_unlock(&(philo->shared->whistleblower));
	usleep(10000);
}

static int	_take_fork(t_philo *philo, pthread_mutex_t mutex, int *fork)
{
	int	winner;

	winner = 0;
	pthread_mutex_lock(&(mutex));
	if (*fork == 0)
	{
		*fork = philo->id;
		winner = philo->id;
		pthread_mutex_lock(&(philo->shared->whistleblower));
		if (display_routine(philo->shared, philo->id, "has taken a fork") != 0)
			return (return_error("display_routine: failed", -5));
		pthread_mutex_unlock(&(philo->shared->whistleblower));
	}
	else if (*fork != philo->id)
		winner = *fork;
	pthread_mutex_unlock(&(mutex));
	return (winner);
}

static void	_give_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->m_left_fork));
	philo->left_fork = 0;
	pthread_mutex_unlock(&(philo->m_left_fork));
	pthread_mutex_lock(philo->m_right_fork);
	*philo->right_fork = 0;
	pthread_mutex_unlock(philo->m_right_fork);
}
