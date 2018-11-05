/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 12:15:12 by mmuamba           #+#    #+#             */
/*   Updated: 2018/08/28 15:21:51 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_len(char const *str, char c)
{
	int	i;
	int	wlen;

	i = 0;
	wlen = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		wlen++;
	}
	return (wlen);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**newstr;

	if (!s || !(newstr = (char **)malloc(sizeof(*newstr) *
					(ft_word_count(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_word_count(s, c))
	{
		k = 0;
		if (!(newstr[i] = ft_strnew(ft_word_len(&s[j], c) + 1)))
			newstr[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			newstr[i][k++] = s[j++];
		newstr[i][k] = '\0';
	}
	newstr[i] = 0;
	return (newstr);
}
