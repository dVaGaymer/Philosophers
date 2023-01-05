/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:52:17 by alopez-g          #+#    #+#             */
/*   Updated: 2023/01/05 20:53:17 by alopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long	aux;
	int		sign;

	aux = 0;
	sign = 1;
	if (!str)
		return (0);
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\t'
		|| *str == '\r' || *str == '\f')
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		aux = aux * 10 + (*str - 48);
		str++;
	}
	return ((int)(aux * sign));
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_strisdigit(char *c)
{
	if (!c)
		return (0);
	if (*c == '-')
		c++;
	while (*c)
	{
		if (!ft_isdigit(*c))
			return (0);
		c++;
	}
	return (1);
}

int	ft_strisfdigit(char *c)
{
	char	p_cnt;

	p_cnt = 0;
	if (!c)
		return (0);
	if (*c == '-')
		c++;
	while (*c)
	{
		if (*c == '.')
			p_cnt++;
		if (!ft_isdigit(*c) && *c != '.')
			return (0);
		c++;
	}
	if (p_cnt > 1)
		return (0);
	return (1);
}
