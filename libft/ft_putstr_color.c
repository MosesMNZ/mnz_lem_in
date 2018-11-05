/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:08:38 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/04 18:43:59 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CRED "\x1B[31m"
#define CGRN "\x1B[32m"
#define CYEL "\x1B[33m"
#define RESET "\033[0m"

static void	color_write(const char *color, char *str)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(RESET);
}

void		ft_putstr_color(char *str, int color)
{
	const char *colors[] =
	{CGRN, CRED, CYEL, RESET};

	color_write(colors[color], str);
}
