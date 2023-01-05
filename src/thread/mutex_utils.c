/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:07:25 by alopez-g          #+#    #+#             */
/*   Updated: 2023/01/05 19:39:06 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void	mutex_take_forks(t_args *args, t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	log_state(args, philo, TAKE_RFORK);
	pthread_mutex_lock(philo->lfork);
	log_state(args, philo, TAKE_LFORK);
}

void	mutex_leave_forks(t_args *args, t_philo *philo)
{
	(void)args;
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

t_bool	mutex_args_save_access(t_args *args, t_bool flag)
{
	pthread_mutex_lock(&args->common_mutex);
	args->run = flag;
	pthread_mutex_unlock(&args->common_mutex);
	return (flag);
}
