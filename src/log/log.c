/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:09:11 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/16 02:01:22 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

void	log_state(t_args *args, int philon, t_philo_action action)
{
	struct timeval t;
	gettimeofday(&t, NULL);
	pthread_mutex_lock(&args->log_mutex);
	printf("%d %d ", t.tv_usec / 1000, philon);
	if (TAKE_FORK == action)
		printf("has taken a fork");
	else if (EAT == action)
		printf("is eating");
	else if (SLEEP == action)
		printf("is sleeping");
	else if (THINK == action)
		printf("is thinking");
	else if (DIED == action)
		printf("died");
	printf("\n");
	pthread_mutex_unlock(&args->log_mutex);
}

void	log_args_print(t_args p)
{
	printf("number_of_philosophers: %d\n", p.nop);
	printf("time_to_die: %d\n", p.ttd);
	printf("time_to_eat: %d\n", p.tte);
	printf("time_to_sleep: %d\n", p.tts);
	if (p.notepme)
		printf("number_of_times_each_philosopher_must_eat: %d\n", p.notepme);
}
