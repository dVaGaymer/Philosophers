/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:14:49 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/30 23:38:32 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

void	threads_start(t_args *args, t_philo **philo)
{
	char			aux;
	int				n;
	t_thread_param	*param;

	aux = 0;
	while (aux < 2)
	{
		n = aux;
		while (n < args->nop)
		{
			param = (t_thread_param *)malloc(sizeof(t_thread_param));
			*param = (t_thread_param){args, (*philo + n)};
			usleep(SAFE_DELAY);
			pthread_create(&((*philo + n)->thread), NULL,
				vital_functions, param);
			n += 2;
		}
		aux++;
	}
	n = -1;
	while (++n < args->nop)
		pthread_join((*philo + n)->thread, NULL);
}
