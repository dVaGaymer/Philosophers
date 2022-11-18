/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:49:51 by al7aro            #+#    #+#             */
/*   Updated: 2022/11/18 16:44:01 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	error_set_error(int *err, int pos)
{
	*err = *err | (1 << pos);
}

t_bool	error_get_error(int err, int pos)
{
	return (!!(err & (1 << pos)));
}

void	error_print_usage(char **argv, int err)
{
	if (error_get_error(err, NOP + NAN))
		printf("number_of_philosophers[%s] not a number\n", *(argv + 1));
	if (error_get_error(err, NOP + INVALID_RANGE))
		printf("number_of_philosophers[%s] not in range\n", *(argv + 1));
	if (error_get_error(err, TTD + NAN))
		printf("time_to_die[%s] is not a number\n", *(argv + 2));
	if (error_get_error(err, TTD + INVALID_RANGE))
		printf("time_to_die[%s] not in range\n", *(argv + 2));
	if (error_get_error(err, TTE + NAN))
		printf("time_to_eat[%s] is not a number\n", *(argv + 3));
	if (error_get_error(err, TTE + INVALID_RANGE))
		printf("time_to_eat[%s] not in range\n", *(argv + 3));
	if (error_get_error(err, TTS + NAN))
		printf("time_to_sleep[%s] is not a number\n", *(argv + 4));
	if (error_get_error(err, TTS + INVALID_RANGE))
		printf("time_to_sleep[%s] not in range\n", *(argv + 4));
	if (error_get_error(err, NOTEPME + NAN))
		printf("number_of_times_each_philosopher_must_eat[%s] \
is not a number\n", *(argv + 5));
	if (error_get_error(err, NOTEPME + INVALID_RANGE))
		printf("number_of_times_each_philosopher_must_eat[%s] \
not in range\n", *(argv + 5));
	printf("\nusage:\n\t./philo number_of_philosophers ");
	printf("time_to_die time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}
