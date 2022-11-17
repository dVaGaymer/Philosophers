/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:16:26 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/17 23:46:13 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>

typedef struct	s_philo_args
{
	unsigned int	nop;
	unsigned int	ttd;
	unsigned int	tte;
	unsigned int	tts;
	unsigned int	notepme;
}				t_philo_args;

void	philo_args_print(t_philo_args philo);

#endif
