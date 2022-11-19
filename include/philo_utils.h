/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:16:26 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/19 01:31:58 by alopez-g         ###   ########.fr       */
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

t_error	philo_table_init(t_args args, char **forks, pthread_t **philo);
char	*philo_right_fork(t_args args, char *forks, int index);
char	*philo_left_fork(t_args args, char *forks, int index);
t_philo	*philo_create_philo(t_args *args, char *lfork, char *rfork);

#endif
