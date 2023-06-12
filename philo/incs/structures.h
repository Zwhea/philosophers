/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:50:40 by twang             #+#    #+#             */
/*   Updated: 2023/06/12 18:19:14 by twang            ###   ########.fr       */
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
	int				time_to_die;	//struct time val o long int???
	int				time_to_eat;	//struct time val o long int???
	int				time_to_sleep;	//struct time val o long int???
	int				must_eat;
	bool			is_dead;
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
	int				start_eating;
	int				end;
	t_data			*shared;
};

#endif
