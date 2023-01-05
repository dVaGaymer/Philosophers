/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <alopez-g@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:57:18 by alopez-g          #+#    #+#             */
/*   Updated: 2023/01/05 20:19:22 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

typedef enum s_bool
{
	TRUE = 1,
	FALSE = 0
}			t_bool;
# define MS_TO_US 1000
# define S_TO_MS 1000
# define S_TO_US 1000000
# define BLACK "\e[0;30m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define MAGENTA "\e[0;35m"
# define CYAN "\e[0;36m"
# define WHITE "\e[0;37m"
# define NC "\e[0m"
# define SAFE_DELAY 2000
# define MAX_NOP 200
# define MIN_TIME 50

typedef long unsigned int	t_time;

#endif
