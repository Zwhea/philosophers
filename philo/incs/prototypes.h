/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:50:59 by twang             #+#    #+#             */
/*   Updated: 2023/06/21 13:03:28 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/*---- includes --------------------------------------------------------------*/

# include "structures.h"

/*---- activities.c ----------------------------------------------------------*/

int				take_fork(t_philo *philo, pthread_mutex_t *mutex, int *fork);
void			give_fork(t_philo *philo);
void			eaten_all_meals(t_philo *philo);
bool			is_he_dead(t_philo *philo);

/*---- end_of_life.c ---------------------------------------------------------*/

int				end_of_life(t_data *data);
int				mutex_destroyer(t_data *data);

/*---- init_philo.c ----------------------------------------------------------*/

int				init_philosophers(t_data *data);

/*---- parsing.c -------------------------------------------------------------*/

int				parse_arguments(t_data *data, int ac, char **av);

/*---- print.c ---------------------------------------------------------------*/

int				print_error(char *msg, int return_val);
int				return_error(char *msg, int return_val);
int				display_routine(t_data *data, int id_philo, char *msg);

/*---- routine.c -------------------------------------------------------------*/

int				routine_philosophers(t_data *data);

/*---- time_utils.c ----------------------------------------------------------*/

bool			timeval_is_inf(struct timeval a, struct timeval b);
struct timeval	int_to_timeval(int time_in_int);
struct timeval	substract_timeval(struct timeval a, struct timeval b);
struct timeval	add_time(struct timeval a, struct timeval b);
struct timeval	get_current_time(t_philo *philo);

/*---- utils.c ---------------------------------------------------------------*/

int				ft_atoi(char *str);
void			ft_bzero(void *dst, size_t n);
void			*ft_calloc(size_t count, size_t size);

#endif