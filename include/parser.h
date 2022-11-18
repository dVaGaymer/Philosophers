/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:34:30 by alopez-g          #+#    #+#             */
/*   Updated: 2022/11/18 16:36:16 by al7aro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "error.h"
# include "philo_args.h"

t_error	parser_parse(int argc, char **argv, t_philo_args *err);

#endif
