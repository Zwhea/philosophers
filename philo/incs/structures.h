/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:50:40 by twang             #+#    #+#             */
/*   Updated: 2023/06/16 17:22:59 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/*---- typedef structures ----------------------------------------------------*/

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

/*---- structures ------------------------------------------------------------*/

struct	s_data
{
	int				nb_of_philo;
	struct timeval	time_to_start;
	struct timeval	time_to_die;
	struct timeval	time_to_eat;
	struct timeval	time_to_sleep;
	int				must_eat;
	bool			the_end;
	pthread_mutex_t	philo_maker;
	pthread_mutex_t	whistleblower;
	t_philo			*table;
};

struct	s_philo
{
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t	m_left_fork;
	pthread_mutex_t	*m_right_fork;
	int				left_fork;
	int				*right_fork;
	struct timeval	start_meal;
	struct timeval	end_meal;
	struct timeval	start_sleep;
	struct timeval	end_sleep;
	bool			is_dead;
	struct timeval	lifespan;
	t_data			*shared;
};

#endif
