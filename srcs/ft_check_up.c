/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuamba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 07:55:59 by mmuamba           #+#    #+#             */
/*   Updated: 2018/09/18 08:27:32 by mmuamba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	check_matching(t_lem_in *lem, char **str, int i, int j)
{
	if ((ft_strequ(lem->rm[i].name, str[0]) &&
	ft_strequ(lem->rm[j].name, str[1])) || (ft_strequ(lem->rm[i].name, str[1])
	&& ft_strequ(lem->rm[j].name, str[0])))
	{
		lem->map[i][j] = 1;
		lem->map[j][i] = 1;
	}
}

int		check_rooms(t_lem_in *lem)
{
	if (lem->rooms <= 0 || lem->rooms > 1000)
	{
		ft_putstr("Error : Invalid rooms\n");
		return (1);
	}
	return (0);
}

int		check_ants(t_lem_in *lem)
{
	if (lem->ants <= 0 || lem->ants > 100)
	{
		ft_putstr("Error : Invalid ants/links\n");
		return (1);
	}
	return (0);
}

int		check_commands(t_lem_in *lem)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (lem->data[i])
	{
		if (ft_strequ("##start", lem->data[i]) ||
				ft_strequ("##end", lem->data[i]))
			flag++;
		i++;
	}
	if (flag < 2)
	{
		ft_putstr("Error : Invalid mandatory commands\n");
		return (1);
	}
	return (0);
}

int		errors_check_up(t_lem_in *lem)
{
	if (check_ants(lem) || check_rooms(lem) || check_commands(lem))
		return (1);
	return (0);
}
