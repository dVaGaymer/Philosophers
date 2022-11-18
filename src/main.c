/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:50:44 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/18 22:27:15 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*vital_functions(void *param)
{
	t_args		args;
	char		*forks[2];

	args = *((t_args *)*((void **)param));
	*(forks) = (char *)*((void **)param + 1);
	*(forks + 1) = (char *)*((void **)param + 2);
	printf("Im a thread\t0:[%p]\n", *forks);
	printf("Im a thread\t1:[%p]\n", *(forks + 1));
	return (NULL);
}

void	create_threads(t_args args, char *forks, pthread_t *philo)
{
	void *param[3];
	int	n;

	*(param) = (void *)&args;
	n = -1;
	while (++n < args.nop)
	{
		*(param + 1) = (void *)philo_left_fork(args, forks, n);
		*(param + 2) = (void *)philo_right_fork(args, forks, n);
		printf("Im NOT a thread\t0:[%p]\n", *(param + 1));
		printf("Im NOT a thread\t1:[%p]\n", *(param + 2));
		pthread_create(philo + n, NULL, vital_functions, param);
	}
	n = -1;
	while (++n < args.nop)
		pthread_join(*(philo + n), NULL);
}

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
