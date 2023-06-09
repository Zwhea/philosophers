/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:50:59 by twang             #+#    #+#             */
/*   Updated: 2023/06/09 15:43:23 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/*---- includes --------------------------------------------------------------*/

# include "structures.h"

/*---- clean_utils.c ---------------------------------------------------------*/

void	mutex_destroyer(t_data *data);

/*---- init_philo.c ----------------------------------------------------------*/

int		init_philosophers(t_data *data);

/*---- parsing.c -------------------------------------------------------------*/

int		parse_arguments(t_data *data, int ac, char **av);

/*---- print.c ---------------------------------------------------------------*/

void	print_error(char *msg);

/*---- routine.c -------------------------------------------------------------*/

int	routine_philosophers(t_data *data);

/*---- utils.c ---------------------------------------------------------------*/

int		ft_atoi(char *str);
void	ft_bzero(void *dst, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif