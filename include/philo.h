/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:31:52 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/16 01:58:55 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
	suseconds_t		init_time;
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				notepme;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	log_mutex;
}				t_args;

typedef struct s_philo
{
	t_args			*args;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	int				id;
}				t_philo;

typedef enum s_philo_action
{
	TAKE_FORK,
	EAT,
	SLEEP,
	THINK,
	DIED
}			t_philo_action;

#endif
