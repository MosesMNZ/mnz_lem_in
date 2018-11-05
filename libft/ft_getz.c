/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:24:50 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/03 18:14:28 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getz(char *num)
{
	if ((num = (char *)malloc(sizeof(char) * (2))))
	{
		num[0] = '0';
		num[1] = '\0';
		return (num);
	}
	else
		return (NULL);
}