/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 07:56:56 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/18 07:56:58 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	moving_2(t_lem_in *lem, int ant, int rm, int count)
{
	lem->rm[lem->rmf[rm - 1]].ants_amount--;
	lem->rm[lem->rmf[rm]].ants_amount++;
	if (rm == lem->len - 1)
	{
		ants_printing(lem, ant + (count - ant), rm);
		moving_1(lem, ant + (count - ant) + 1, rm - 1, count + 1);
	}
	else
	{
		ants_printing(lem, ant, rm);
		moving_1(lem, ant + 1, rm - 1, count);
	}
}

int		moving_1(t_lem_in *lem, int ant, int rm, int count)
{
	if (lem->rm[lem->rmf[lem->len - 1]].ants_amount == lem->ants)
		return (1);
	if (rm <= 0)
	{
		write(1, "\n", 1);
		moving_1(lem, 1, lem->len - 1, count);
		return (0);
	}
	else if (lem->rm[lem->rmf[rm - 1]].ants_amount == 0
		&& lem->rm[lem->rmf[rm]].ants_amount >= 1)
		return (0);
	else if (lem->rm[lem->rmf[rm - 1]].ants_amount >= 1)
	{
		moving_2(lem, ant, rm, count);
	}
	moving_1(lem, ant, rm - 1, count);
	return (0);
}

void	ants_moving(t_lem_in *lem)
{
	lem->rm[lem->rmf[0]].ants_amount = lem->ants;
	moving_1(lem, 1, lem->len - 1, 1);
	write(1, "\n", 1);
}

void	rooms_sorting(t_lem_in *lem)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	s = ft_strsplit(lem->lst, '-');
	while (*(s + i))
	{
		j = 0;
		while (j <= lem->rooms - 1)
		{
			if (ft_strequ(*(s + i), lem->rm[j].name))
				lem->rmf[i] = j;
			j++;
		}
		free(s[i]);
		i++;
	}
	free(s);
}
