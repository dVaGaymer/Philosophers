/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:31:52 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/19 02:29:37 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_args
{
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				notepme;
	pthread_mutex_t	mutex;
}				t_args;

typedef struct s_philo
{
	t_args	*args;
	char	*lfork;
	char	*rfork;
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
