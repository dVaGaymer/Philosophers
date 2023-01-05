/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:50:44 by alopez-g          #+#    #+#             */
/*   Updated: 2023/01/05 20:30:05 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "main.h"

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
