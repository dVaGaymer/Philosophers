/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_table.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:16:26 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/18 22:31:01 by al7aro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TABLE_H
# define PHILO_TABLE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# include "error.h"
# include "args.h"

t_error	philo_table_init(t_args args, char **forks, pthread_t **philo);
char	*philo_right_fork(t_args args, char *forks, int index);
char	*philo_left_fork(t_args args, char *forks, int index);

#endif
