/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:14:49 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/19 01:38:15 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void	*vital_functions(void *param)
{
	t_args		args;
	char		*forks[2];

	args = *((t_args *)*((void **)param));
	*(forks) = (char *)*((void **)param + 1);
	*(forks + 1) = (char *)*((void **)param + 2);
	free(param);
	return (NULL);
}

void	create_threads(t_args args, char *forks, pthread_t *philo)
{
	int		n;

	n = -1;
	while (++n < args.nop)
	{
		pthread_create(philo + n, NULL, vital_functions,
			(void *)philo_create_philo(&args,
				philo_left_fork(args, forks, n),
				philo_right_fork(args, forks, n)));
	}
	n = -1;
	while (++n < args.nop)
		pthread_join(*(philo + n), NULL);
}
