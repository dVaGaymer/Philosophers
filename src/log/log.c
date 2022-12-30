/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:09:11 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/30 23:38:17 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

void	log_state(t_args *args, t_philo *philo, t_philo_action action)
{
	struct timeval	t;
	suseconds_t		time;

	gettimeofday(&t, NULL);
	time = (philo_get_utime() - args->init_time) * US_TO_MS;
	pthread_mutex_lock(&args->common_mutex);
	if (TAKE_LFORK == action)
		printf(RED"%d %d has taken left fork", time, philo->id);
	else if (TAKE_RFORK == action)
		printf(RED"%d %d has taken right fork", time, philo->id);
	else if (EAT == action)
		printf(YELLOW"%d %d is eating", time, philo->id);
	else if (SLEEP == action)
		printf(CYAN"%d %d is sleeping", time, philo->id);
	else if (THINK == action)
		printf(MAGENTA"%d %d is thinking", time, philo->id);
	else if (DIED == action)
		printf("%d %d died [delay: %d]", time, philo->id,
			(philo_get_utime() * US_TO_MS - philo->time_of_last_eat)
			- args->ttd);
	printf("\n");
	pthread_mutex_unlock(&args->common_mutex);
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
