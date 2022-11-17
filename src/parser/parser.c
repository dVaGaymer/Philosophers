/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:34:11 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/17 23:51:39 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_error	parser_parse(int argc, char **argv, t_philo_args *ret)
{
	t_philo_args	philo;

	if (5 != argc && 6 != argc)
		return (ERROR);
	philo.nop = ft_atoi(*(argv + 1));
	philo.ttd = ft_atoi(*(argv + 2));
	philo.tte = ft_atoi(*(argv + 3));
	philo.tts = ft_atoi(*(argv + 4));
	philo.notepme = 0;
	if (6 == argc)
		philo.notepme = ft_atoi(*(argv + 5));
	*ret = philo;
	return (SUCCESS);
}
