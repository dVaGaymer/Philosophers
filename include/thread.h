/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:15:09 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/19 01:18:55 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <stdio.h>
# include <pthread.h>

# include "philo.h"
# include "philo_utils.h"

void	*vital_functions(void *param);
void	create_threads(t_args args, char *forks, pthread_t *philo);

#endif
