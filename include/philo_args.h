/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:16:26 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/18 13:49:22 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ARGS_H
# define PHILO_ARGS_H

# include <stdio.h>

typedef struct s_philo_args
{
	int	nop;
	int	ttd;
	int	tte;
	int	tts;
	int	notepme;
}				t_philo_args;

typedef enum s_philo_act
{
	TAKE_FORK,
	EAT,
	SLEEP,
	THINK,
	DIED
}				t_philo_action;

void	philo_args_print(t_philo_args philo);

#endif
