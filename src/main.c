/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:50:44 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/18 16:29:36 by al7aro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_philo_args	philo;
	t_error			err;

	err = parser_parse(argc, argv, &philo);
	if (SUCCESS != err)
	{
		parser_print_usage(argv, err);
		return (err);
	}
	return (SUCCESS);
}
