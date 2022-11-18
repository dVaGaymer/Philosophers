/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al7aro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:49:51 by al7aro            #+#    #+#             */
/*   Updated: 2022/11/18 15:56:29 by al7aro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	error_set_error(int *err, int pos)
{
	*err = *err | (1 << pos);
}

t_bool	error_get_error(int err, int pos)
{
	return (!!(err & (1 << pos)));
}