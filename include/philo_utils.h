/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:16:26 by alopez-g          #+#    #+#             */
/*   Updated: 2023/01/05 14:31:54 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_UTILS_H
# define PHILO_UTILS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# include "error.h"
# include "philo.h"

t_error			philo_init(t_args *args, t_philo **philo);
pthread_mutex_t	*philo_right_fork(t_args *args,
					pthread_mutex_t *forks, int index);
pthread_mutex_t	*philo_left_fork(t_args *args,
					pthread_mutex_t *forks, int index);
t_philo			philo_create_philo(pthread_mutex_t *lfork,
					pthread_mutex_t *rfork, int n);
suseconds_t		philo_get_mstime(void);
void			ft_usleep(t_time t);

#endif
