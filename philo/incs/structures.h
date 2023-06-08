/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:50:40 by twang             #+#    #+#             */
/*   Updated: 2023/06/08 11:38:38 by twang            ###   ########.fr       */
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
	int			nb_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	bool		is_dead;
	pthread_t	thread_id;

	t_philo		*table;
};

struct	s_philo
{
	int			id;
	pthread_t	thread_id;
	t_data		*shared;
};

#endif
