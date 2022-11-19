/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:14:49 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/19 01:56:53 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void	*vital_functions(void *param)
{
	t_philo	philo;

	philo = (t_philo)(*((t_philo *)param));
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
