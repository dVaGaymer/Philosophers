/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:47:26 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/19 01:32:18 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

char	*philo_right_fork(t_args args, char *forks, int index)
{
	if (index >= args.nop || index < 0)
		return (NULL);
	if (index == args.nop - 1)
		return (forks);
	return (forks + index + 1);
}

char	*philo_left_fork(t_args args, char *forks, int index)
{
	if (index >= args.nop || index < 0)
		return (NULL);
	return (forks + index);
}

t_error	philo_table_init(t_args args, char **forks, pthread_t **philo)
{
	*forks = (char *)malloc(sizeof(char) * args.nop);
	if (!*forks)
		return (ERROR);
	*philo = (pthread_t *)malloc(sizeof(pthread_t) * args.nop);
	if (!*philo)
		return (ERROR);
	memset(*forks, 0, args.nop);
	return (SUCCESS);
}

t_philo	*philo_create_philo(t_args *args, char *lfork, char *rfork)
{
	t_philo	*ret;

	ret = (t_philo *)malloc(sizeof(t_philo));
	ret->args = args;
	ret->lfork = lfork;
	ret->rfork = rfork;
	return (ret);
}
