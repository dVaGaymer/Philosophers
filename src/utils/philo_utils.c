/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:47:26 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/19 15:52:26 by alopez-g         ###   ########.fr       */
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
		pthread_mutex_init(args->mutex, NULL);
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
