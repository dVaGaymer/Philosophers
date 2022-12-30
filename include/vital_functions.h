/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vital_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:06:57 by alopez-g          #+#    #+#             */
/*   Updated: 2022/12/30 18:10:36 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VITAL_FUNCTIONS_H
# define VITAL_FUNCTIONS_H

# include <stdio.h>
# include <pthread.h>

# include "thread.h"
# include "philo.h"
# include "log.h"
# include "error.h"
# include "philo_utils.h"

void	*vital_functions(void *param);

#endif
