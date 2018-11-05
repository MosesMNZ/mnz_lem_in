/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 15:17:50 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/04 18:41:21 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_word_count(char const *str, char c)
{
	int wcount;
	int i;

	wcount = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0' && str[i] != c)
			wcount++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (wcount);
}
