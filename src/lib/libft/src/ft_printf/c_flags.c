/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:17:38 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/17 18:27:35 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** Function: apply_c_flags
** ------------------------
**
** const char *pos: input string
** t_info *si:      info structure
** t_flags *sf:     flag structure
** char c:          char to print
*/

void	c_flags(t_info *si, t_flags *sf, int c)
{
	if (sf->neg)
		write(1, &c, 1);
	space(sf->width - 1, sf->zero = 0, si);
	if (!sf->neg)
		write(1, &c, 1);
	si->t += 1;
}
