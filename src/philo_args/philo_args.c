/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:47:26 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/17 23:51:53 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_args.h"

void	philo_args_print(t_philo_args p)
{
	printf("number_of_philosophers: %u\n", p.nop);
	printf("time_to_die: %u\n", p.ttd);
	printf("time_to_eat: %u\n", p.tte);
	printf("time_to_sleep: %u\n", p.tts);
	if (p.notepme)
		printf("number_of_times_each_philosopher_must_eat: %u\n", p.notepme);
}
