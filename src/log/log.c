/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:09:11 by alopez-g          #+#    #+#             */
/*   Updated: 2023/01/05 19:46:18 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

void	log_state(t_args *args, t_philo *philo, t_philo_action action)
{
	suseconds_t		time;

	pthread_mutex_lock(&args->common_mutex);
	if (!args->run)
	{
		pthread_mutex_unlock(&args->common_mutex);
		return ;
	}
	time = (philo_get_mstime() - args->init_time);
	if (TAKE_LFORK == action)
		printf("%d %d has taken left fork\n", time, philo->id);
	else if (TAKE_RFORK == action)
		printf("%d %d has taken right fork\n", time, philo->id);
	else if (EAT == action)
		printf("%d %d is eating\n", time, philo->id);
	else if (SLEEP == action)
		printf("%d %d is sleeping\n", time, philo->id);
	else if (THINK == action)
		printf("%d %d is thinking\n", time, philo->id);
	else if (DIED == action)
		printf("%d %d died\n", time, philo->id);
	pthread_mutex_unlock(&args->common_mutex);
}

void	log_args_print(t_args p)
{
	printf("number_of_philosophers: %d\n", p.nop);
	printf("time_to_die: %lu\n", p.ttd);
	printf("time_to_eat: %lu\n", p.tte);
	printf("time_to_sleep: %lu\n", p.tts);
	if (p.notepme)
		printf("number_of_times_each_philosopher_must_eat: %d\n", p.notepme);
}
