/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:34:30 by alopez-g          #+#    #+#             */
/*   Updated: 2023/01/05 20:59:02 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "std_utils.h"
# include "error.h"
# include "philo_utils.h"

t_error	parser_parse(int argc, char **argv, t_args *err);

#endif
