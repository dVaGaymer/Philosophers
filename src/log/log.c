/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:09:11 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/18 15:09:45 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"

void	log_state(int philon, int time, t_philo_action action)
{
	printf("%d %d ", time, philon);
	if (TAKE_FORK == action)
		printf("has taken a fork");
	else if (EAT == action)
		printf("is eating");
	else if (SLEEP == action)
		printf("is sleeping");
	else if (THINK == action)
		printf("is thinking");
	else if (DIED == action)
		printf("died");
	printf("\n");
}
