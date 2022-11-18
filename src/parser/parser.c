/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:34:11 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/18 16:34:37 by al7aro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"

int	str_valid(const char *str, t_philo_args_type t, int *err)
{
	int		num;
	size_t	i;

	(void)err;
	(void)t;
	i = -1;
	while (*(str + ++i))
	{
		if ((!ft_isdigit(*(str + i)) && *(str + i) != '-')
			|| (*(str + i) == '-' && i != 0))
		{
			error_set_error(err, t + NAN);
			return (0);
		}
	}
	num = ft_atoi(str);
	if (num <= 0)
		error_set_error(err, t + INVALID_RANGE);
	return (num);
}

void	parser_print_usage(char **argv, int err)
{
	if (error_get_error(err, NOP + NAN))
		printf("nomber_of_philosophers[%s] not a number\n", *(argv + 1));
	if (error_get_error(err, NOP + INVALID_RANGE))
		printf("nomber_of_philosophers[%s] not in range\n", *(argv + 1));
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

t_error	parser_parse(int argc, char **argv, t_philo_args *ret)
{
	t_philo_args	philo;
	int				err;

	err = 0;
	philo.notepme = 0;
	if (6 == argc)
		philo.notepme = str_valid(*(argv + 5), NOTEPME, &err);
	else if (5 != argc)
		return (INOA);
	philo.nop = str_valid(*(argv + 1), NOP, &err);
	philo.ttd = str_valid(*(argv + 2), TTD, &err);
	philo.tte = str_valid(*(argv + 3), TTE, &err);
	philo.tts = str_valid(*(argv + 4), TTS, &err);
	*ret = philo;
	return (err);
}
