/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:50:44 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/18 13:02:16 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_philo_args	philo;
	t_error			err;

	err = parser_parse(argc, argv, &philo);
	if (SUCCESS != err)
		return (err);
	philo_args_print(philo);
	return (0);
}
