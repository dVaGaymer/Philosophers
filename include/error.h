/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:06:57 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/18 15:26:26 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_error
{
	ERROR = -1,
	SUCCESS = 0,
	NEGATIVE = 1,
	NAN = 2,
	INVALID_NUMBER = 3
}			t_error;

typedef enum e_philo_args_type
{
	NOP = 0,
	TTD = 3,
	TTE = 6,
	TTS = 9,
	NOTEPME = 12
}			t_philo_arg_type;

#endif
