/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:08:49 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/18 18:32:41 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "log.h"
# include "args.h"
# include "philo_table.h"

typedef enum s_philo_action
{
	TAKE_FORK,
	EAT,
	SLEEP,
	THINK,
	DIED
}			t_philo_action;

void	log_args_print(t_args philo);
void	log_state(int philon, int time, t_philo_action action);

#endif
