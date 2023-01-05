/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:31:52 by alopez-g          #+#    #+#             */
/*   Updated: 2023/01/05 15:21:28 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

# include "macro.h"

typedef struct s_args
{
	t_time			init_time;
	t_bool			run;
	int				nop;
	t_time			ttd;
	t_time			tte;
	t_time			tts;
	int				notepme;
	pthread_mutex_t	common_mutex;
	pthread_mutex_t	*aux_mutex_list;
}				t_args;

typedef struct s_philo
{
	int				id;
	int				eat_times;
	t_time			time_of_last_eat;
	pthread_t		thread;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
}				t_philo;

typedef enum s_philo_action
{
	FINISHED_ALL_MEALS = -1,
	TAKE_LFORK,
	TAKE_RFORK,
	EAT,
	SLEEP,
	THINK,
	DIED
}			t_philo_action;

#endif
