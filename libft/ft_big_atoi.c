/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:43:57 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/17 17:59:38 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>

intmax_t	ft_big_atoi(const char *str)
{
	int			sign;
	intmax_t	number;

	number = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = sign * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str > 47) && (*str < 58))
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	return (number * sign);
}
