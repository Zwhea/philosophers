/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:38:24 by twang             #+#    #+#             */
/*   Updated: 2023/06/21 14:38:50 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*---- prototypes ------------------------------------------------------------*/

static int	_routine(t_philo *philo);
static void	_thinking(t_philo *philo);
static void	_eating(t_philo *philo);
static void	_sleeping(t_philo *philo);

/*----------------------------------------------------------------------------*/

int	routine_philosophers(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(data->launcher));
	while (i < data->nb_of_philo)
	{
		if (pthread_create(&data->table[i].thread_id, NULL, (void *)_routine, \
								&(data->table[i])) != 0)
			return (return_error("thread create: failed", -4));
		i++;
	}
	if (gettimeofday(&data->time_to_start, NULL) == -1)
		return (return_error("get time of day: failed", -5));
	pthread_mutex_unlock(&(data->launcher));
	return (0);
}

static int	_routine(t_philo *philo)
{
	philo->is_dead = false;
	pthread_mutex_lock(&(philo->shared->launcher));
	pthread_mutex_unlock(&(philo->shared->launcher));
	philo->lifespan = philo->shared->time_to_die;
	if (philo->id % 2 != 0)
		usleep(40000);
	while (!(philo->is_dead))
	{
		pthread_mutex_lock(&(philo->shared->watchman));
		if (philo->shared->the_end)
		{
			pthread_mutex_unlock(&(philo->shared->watchman));
			return (0);
		}
		pthread_mutex_unlock(&(philo->shared->watchman));
		_thinking(philo);
		_eating(philo);
		_sleeping(philo);
	}
	return (0);
}

static void	_thinking(t_philo *philo)
{
	int				left;
	int				right;

	left = 0;
	right = 0;
	pthread_mutex_lock(&(philo->shared->whistleblower));
	if (display_routine(philo->shared, philo->id, "is thinking") != 0)
	{
		printf("display_routine: failed\n");
		return ;
	}
	pthread_mutex_unlock(&(philo->shared->whistleblower));
	while (philo->id != left || philo->id != right \
				|| &(philo->left_fork) == philo->right_fork)
	{
		usleep(philo->shared->nb_of_philo * 10);
		if (is_he_dead(philo) != false)
			return ;
		left = take_fork(philo, &(philo->m_left_fork), &(philo->left_fork));
		right = take_fork(philo, philo->m_right_fork, philo->right_fork);
	}
}

static void	_eating(t_philo *philo)
{
	if (philo->is_dead)
		return ;
	philo->start_meal = get_current_time(philo);
	philo->end_meal = add_time(philo->start_meal, philo->shared->time_to_eat);
	philo->lifespan = add_time(philo->start_meal, philo->shared->time_to_die);
	pthread_mutex_lock(&(philo->shared->whistleblower));
	if (display_routine(philo->shared, philo->id, "is eating") != 0)
	{
		printf("display_routine: failed\n");
		return ;
	}
	pthread_mutex_unlock(&(philo->shared->whistleblower));
	while (timeval_is_inf(get_current_time(philo), philo->end_meal) != false)
	{
		usleep(philo->shared->nb_of_philo * 10);
		if (is_he_dead(philo) != false)
		{
			give_fork(philo);
			return ;
		}
	}
	give_fork(philo);
	if (philo->meal != -1)
		eaten_all_meals(philo);
}

static void	_sleeping(t_philo *philo)
{
	if (philo->is_dead)
		return ;
	philo->start_sleep = get_current_time(philo);
	philo->end_sleep = add_time(philo->start_sleep, \
												philo->shared->time_to_sleep);
	pthread_mutex_lock(&(philo->shared->whistleblower));
	if (display_routine(philo->shared, philo->id, "is sleeping") != 0)
	{
		printf("display_routine: failed\n");
		return ;
	}
	pthread_mutex_unlock(&(philo->shared->whistleblower));
	while (timeval_is_inf(get_current_time(philo), philo->end_sleep) != false)
	{
		if (is_he_dead(philo) != false)
			return ;
		usleep(philo->shared->nb_of_philo * 10);
	}
}
