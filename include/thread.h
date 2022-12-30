/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:15:09 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/30 12:44:24 by alopez-g         ###   ########.fr       */
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

typedef struct s_thread_param
{
	t_args	*args;
	t_philo	*philo;
}				t_thread_param;

void	*vital_functions(void *param);
void	threads_start(t_args *args, t_philo **philo);

#endif
