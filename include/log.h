/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:08:49 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/16 01:43:28 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include "log.h"
# include "philo.h"
# include "philo_utils.h"

void	log_args_print(t_args philo);
void	log_state(t_args *args, int philon, t_philo_action action);

#endif
