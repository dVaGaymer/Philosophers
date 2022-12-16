/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:47:26 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/16 01:59:41 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

pthread_mutex_t	*philo_right_fork(t_args args,
		pthread_mutex_t *forks, int index)
{
	if (index >= args.nop || index < 0)
		return (NULL);
	if (index == args.nop - 1)
		return (forks);
	return (forks + index + 1);
}

pthread_mutex_t	*philo_left_fork(t_args args,
		pthread_mutex_t *forks, int index)
{
	if (index >= args.nop || index < 0)
		return (NULL);
	return (forks + index);
}

void	philo_init_time(t_args *args)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	args->init_time = t.tv_usec;
}

t_error	philo_table_init(t_args *args, pthread_t **philo)
{
	int	i;

	args->mutex
		= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * args->nop);
	if (!args->mutex)
		return (ERROR);
	*philo = (pthread_t *)malloc(sizeof(pthread_t) * args->nop);
	if (!*philo)
		return (ERROR);
	i = -1;
	while (++i < args->nop)
		pthread_mutex_init(args->mutex + i, NULL);
	pthread_mutex_init(&args->log_mutex, NULL);
	philo_init_time(args);
	return (SUCCESS);
}

t_philo	*philo_create_philo(t_args *args,
		pthread_mutex_t *lfork, pthread_mutex_t *rfork, int n)
{
	t_philo	*ret;

	ret = (t_philo *)malloc(sizeof(t_philo));
	ret->args = args;
	ret->lfork = lfork;
	ret->rfork = rfork;
	ret->id = n;
	return (ret);
}
