/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:15:09 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/19 15:42:13 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <stdio.h>
# include <pthread.h>

# include "philo.h"
# include "log.h"
# include "error.h"
# include "philo_utils.h"

void	*vital_functions(void *param);
void	threads_start(t_args args, pthread_t *philo);

#endif
