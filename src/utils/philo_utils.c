/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:47:26 by alopez-g          #+#    #+#             */
/*   Updated: 2023/01/05 16:12:22 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

pthread_mutex_t	*philo_right_fork(t_args *args,
		pthread_mutex_t *forks, int index)
{
	if (index >= args->nop || index < 0)
		return (NULL);
	if (index + 1 == args->nop)
		return (forks);
	return (forks + index + 1);
}

pthread_mutex_t	*philo_left_fork(t_args *args,
		pthread_mutex_t *forks, int index)
{
	if (index >= args->nop || index < 0)
		return (NULL);
	return (forks + index);
}

suseconds_t	philo_get_mstime(void)
{
	long unsigned int	time;
	struct timeval		t;

	gettimeofday(&t, NULL);
	time = t.tv_sec * S_TO_MS + t.tv_usec / S_TO_MS;
	return (time);
}

t_error	philo_init(t_args *args, t_philo **philo)
{
	int	i;

	args->aux_mutex_list
		= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args->nop);
	if (!args->aux_mutex_list)
		return (ERROR);
	*philo = (t_philo *)malloc(sizeof(t_philo) * args->nop);
	if (!*philo)
		return (ERROR);
	i = -1;
	while (++i < args->nop)
	{
		pthread_mutex_init(args->aux_mutex_list + i, NULL);
		*(*philo + i) = philo_create_philo(
				philo_left_fork(args, args->aux_mutex_list, i),
				philo_right_fork(args, args->aux_mutex_list, i), i);
	}
	pthread_mutex_init(&args->common_mutex, NULL);
	return (SUCCESS);
}

t_philo	philo_create_philo(pthread_mutex_t *lfork, pthread_mutex_t *rfork,
			int n)
{
	t_philo	ret;

	ret.lfork = lfork;
	ret.rfork = rfork;
	ret.id = n;
	ret.eat_times = 0;
	ret.time_of_last_eat = 0;
	return (ret);
}
