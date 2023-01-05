/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vital_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:08:10 by alopez-g          #+#    #+#             */
/*   Updated: 2023/01/05 19:39:33 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vital_functions.h"

t_bool	step_wait(t_args *args, t_philo *philo, t_time t)
{
	t_time	time;

	time = philo_get_mstime();
	if (t < 0)
		return (TRUE);
	while ((philo_get_mstime() - time < t))
	{
		if (philo_get_mstime() - philo->time_of_last_eat > args->ttd)
			return (FALSE);
		usleep(MS_TO_US);
	}
	return (TRUE);
}

t_bool	vital_sleep(t_args *args, t_philo *philo)
{
	log_state(args, philo, SLEEP);
	if (!step_wait(args, philo, args->tts))
	{
		log_state(args, philo, DIED);
		return (mutex_args_save_access(args, FALSE));
	}
	return (TRUE);
}

t_bool	vital_eat(t_args *args, t_philo *philo)
{
	mutex_take_forks(args, philo);
	log_state(args, philo, EAT);
	philo->eat_times++;
	philo->time_of_last_eat = philo_get_mstime();
	if (!step_wait(args, philo, args->tte))
	{
		log_state(args, philo, DIED);
		return (mutex_args_save_access(args, FALSE));
	}
	mutex_leave_forks(args, philo);
	if (philo->eat_times >= args->notepme && args->notepme)
		return (FALSE);
	return (TRUE);
}

t_bool	vital_think(t_args *args, t_philo *philo)
{
	log_state(args, philo, THINK);
	if (!step_wait(args, philo, args->tte - args->tts))
	{
		log_state(args, philo, DIED);
		return (mutex_args_save_access(args, FALSE));
	}
	return (TRUE);
}

void	*vital_functions(void *param)
{
	t_args	*args;
	t_philo	*philo;

	args = ((t_thread_param *)param)->args;
	philo = ((t_thread_param *)param)->philo;
	free(param);
	philo->time_of_last_eat = philo_get_mstime();
	pthread_mutex_lock(&args->common_mutex);
	if (args->nop == 1)
	{
		pthread_mutex_unlock(&args->common_mutex);
		log_state(args, philo, DIED);
		return (NULL);
	}
	pthread_mutex_unlock(&args->common_mutex);
	while (TRUE)
	{
		if (!vital_eat(args, philo))
			return (NULL);
		if (!vital_sleep(args, philo))
			return (NULL);
		if (!vital_think(args, philo))
			return (NULL);
	}
	return (NULL);
}
