/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:14:49 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/19 15:45:10 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

/*
 * eat
 * sleep
 * think (waiting for a fork)
 * */
void	*vital_functions(void *param)
{
	t_philo	philo;

	philo = (t_philo)(*((t_philo *)param));
	log_state(philo.id, 0, THINK);
	pthread_mutex_lock(philo.lfork);
	log_state(philo.id, 0, EAT);
	sleep(3);
	pthread_mutex_unlock(philo.lfork);
	log_state(philo.id, 0, SLEEP);
	sleep(3);
	free(param);
	return (NULL);
}

void	threads_start(t_args args, pthread_t *philo)
{
	int				n;

	n = -1;
	while (++n < args.nop)
	{
		pthread_create(philo + n, NULL, vital_functions,
			(void *)philo_create_philo(&args,
				philo_left_fork(args, args.mutex + n, n),
				philo_right_fork(args, args.mutex + n, n), n));
	}
	n = -1;
	while (++n < args.nop)
		pthread_join(*(philo + n), NULL);
}
