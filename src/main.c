/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:50:44 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/30 23:39:22 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "main.h"

void	clean_exit(void)
{
}

/*
 * TODO:
 * 		free
 * 		destroy mutex
 * 		etc
 * */
int	main(int argc, char **argv)
{
	t_args	args;
	t_philo	*philo;
	t_error	err;

	err = parser_parse(argc, argv, &args);
	if (SUCCESS != err)
	{
		error_print_usage(argv, err);
		return (err);
	}
	if (SUCCESS != philo_init(&args, &philo))
		return (ERROR);
	threads_start(&args, &philo);
	return (SUCCESS);
}
