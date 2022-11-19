/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:50:44 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/19 01:41:04 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_args		args;
	char		*forks;
	pthread_t	*philo;
	t_error		err;

	err = parser_parse(argc, argv, &args);
	if (SUCCESS != err)
	{
		error_print_usage(argv, err);
		return (err);
	}
	if (SUCCESS != philo_table_init(args, &forks, &philo))
		return (ERROR);
	create_threads(args, forks, philo);
	return (SUCCESS);
}
