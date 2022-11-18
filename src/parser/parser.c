/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:34:11 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/18 13:02:53 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static const char	*str_valid(const char *str)
{
	size_t	i;

	i = -1;
	while (*(str + ++i))
	{
		if (!ft_isdigit(*(str + i)))
			return (NULL);
	}
	return (str);
}

t_error	parser_parse(int argc, char **argv, t_philo_args *ret)
{
	t_philo_args	philo;

	philo.notepme = 0;
	if (6 == argc)
	{
		philo.notepme = ft_atoi(str_valid(*(argv + 5)));
		if (philo.notepme <= 0)
			return (ERROR);
	}
	else if (5 != argc)
		return (ERROR);
	philo.nop = ft_atoi(str_valid(*(argv + 1)));
	philo.ttd = ft_atoi(str_valid(*(argv + 2)));
	philo.tte = ft_atoi(str_valid(*(argv + 3)));
	philo.tts = ft_atoi(str_valid(*(argv + 4)));
	if (philo.nop <= 0 || philo.ttd <= 0 || philo.tte <= 0 || philo.tts <= 0)
		return (ERROR);
	*ret = philo;
	return (SUCCESS);
}
