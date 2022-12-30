/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:31:52 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/30 23:35:53 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

# include "macro.h"

typedef struct s_args
{
	suseconds_t		init_time;
	t_bool			run;
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				notepme;
	pthread_mutex_t	common_mutex;
}				t_args;

typedef struct s_philo
{
	int				id;
	int				eat_times;
	int				time_of_last_eat;
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
