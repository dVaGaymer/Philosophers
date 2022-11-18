/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:47:26 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/18 11:56:16 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_args.h"

void	philo_args_print(t_philo_args p)
{
	printf("number_of_philosophers: %d\n", p.nop);
	printf("time_to_die: %d\n", p.ttd);
	printf("time_to_eat: %d\n", p.tte);
	printf("time_to_sleep: %d\n", p.tts);
	if (p.notepme)
		printf("number_of_times_each_philosopher_must_eat: %d\n", p.notepme);
}
