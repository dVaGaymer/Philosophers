/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:15:09 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/19 02:17:13 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <stdio.h>
# include <pthread.h>

# include "philo.h"
# include "error.h"
# include "philo_utils.h"

void	*vital_functions(void *param);
void	threads_start(t_args args, char *forks, pthread_t *philo);

#endif
