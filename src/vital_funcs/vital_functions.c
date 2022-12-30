/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vital_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:08:10 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/30 23:37:43 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vital_functions.h"

void	process_death(t_args *args, t_philo *philo, int wait_time)
{
	int	time_since_eat;

	time_since_eat = (philo_get_utime() * US_TO_MS - philo->time_of_last_eat);
	if (time_since_eat < 0)
		time_since_eat = 0;
	if (time_since_eat > args->ttd || args->ttd - time_since_eat < wait_time)
	{
		if (time_since_eat > args->ttd)
			time_since_eat = 0;
		usleep((args->ttd - time_since_eat) * MS_TO_US);
		log_state(args, philo, DIED);
	}
}

void	vital_sleep(t_args *args, t_philo *philo)
{
	log_state(args, philo, SLEEP);
	process_death(args, philo, args->tts);
	usleep(args->tts * MS_TO_US);
}

t_bool	vital_eat(t_args *args, t_philo *philo)
{
	pthread_mutex_lock(philo->rfork);
	log_state(args, philo, TAKE_RFORK);
	pthread_mutex_lock(philo->lfork);
	log_state(args, philo, TAKE_LFORK);
	log_state(args, philo, EAT);
	philo->eat_times++;
	process_death(args, philo, args->tte);
	philo->time_of_last_eat = philo_get_utime() * US_TO_MS;
	usleep(args->tte * MS_TO_US);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	if (philo->eat_times >= args->notepme)
		return (TRUE);
	return (FALSE);
}

void	*vital_functions(void *param)
{
	t_args	*args;
	t_philo	*philo;

	free(param);
	args = ((t_thread_param *)param)->args;
	philo = ((t_thread_param *)param)->philo;
	pthread_mutex_lock(&args->common_mutex);
	philo->time_of_last_eat = args->init_time;
	pthread_mutex_unlock(&args->common_mutex);
	while (args->run)
	{
		usleep(SAFE_DELAY);
		if (vital_eat(args, philo))
			return (NULL);
		vital_sleep(args, philo);
	}
	return (NULL);
}
