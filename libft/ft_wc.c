/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:09:54 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/18 15:11:04 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wc(char *s, char c)
{
	int	i;
	int flag;
	int	words;

	i = 0;
	flag = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i] != c) && flag == 0)
		{
			flag = 1;
			words += 1;
		}
		else if (s[i] == c)
		{
			flag = 0;
		}
		i++;
	}
	return (words);
}
