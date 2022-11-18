/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:34:30 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/17 23:48:46 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "parser.h"
# include "error.h"
# include "philo_args.h"

t_error	parser_parse(int argc, char **argv, t_philo_args *err);

#endif
