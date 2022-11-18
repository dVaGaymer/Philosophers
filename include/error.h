/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:06:57 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/18 16:37:02 by al7aro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "macro.h"
# include <stdio.h>

typedef enum e_error
{
	ERROR = -1,
	SUCCESS = 0,
	INOA = 1,
	INVALID_RANGE = 2,
	NAN = 3,
}			t_error;

typedef enum e_philo_args_type
{
	NOP = 0,
	TTD = 2,
	TTE = 4,
	TTS = 6,
	NOTEPME = 8
}			t_philo_args_type;

void	error_set_error(int *err, int pos);
t_bool	error_get_error(int err, int pos);
void	error_print_usage(char **argv, int err);

#endif
