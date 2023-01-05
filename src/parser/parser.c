/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:34:11 by alopez-g          #+#    #+#             */
/*   Updated: 2023/01/05 20:21:19 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"

static int	str_valid(const char *str, t_philo_args_type t, int *err)
{
	int		num;
	size_t	i;

	(void)err;
	(void)t;
	i = -1;
	while (*(str + ++i) || (!*(str + i) && 0 == i))
	{
		if ((!ft_isdigit(*(str + i)) && *(str + i) != '-')
			|| (*(str + i) == '-' && i != 0))
		{
			error_set_error(err, t + NAN);
			return (0);
		}
	}
	num = ft_atoi(str);
	if ((num <= 0)
		|| (t != NOP && num < MIN_TIME)
		|| (t == NOP && num > MAX_NOP))
		error_set_error(err, t + INVALID_RANGE);
	return (num);
}

t_error	parser_parse(int argc, char **argv, t_args *ret)
{
	t_args	args;
	int		err;

	err = 0;
	args.notepme = 0;
	if (6 == argc)
		args.notepme = str_valid(*(argv + 5), NOTEPME, &err);
	else if (5 != argc)
		return (INOA);
	args.nop = str_valid(*(argv + 1), NOP, &err);
	args.ttd = str_valid(*(argv + 2), TTD, &err);
	args.tte = str_valid(*(argv + 3), TTE, &err);
	args.tts = str_valid(*(argv + 4), TTS, &err);
	args.run = TRUE;
	args.init_time = philo_get_mstime();
	*ret = args;
	return (err);
}
