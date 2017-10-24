/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:12:56 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 14:52:01 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_z(t_m *m, char **info, int x, int y)
{
	char **tmp;

	if (ft_strchr(info[x], ','))
	{
		if (!(tmp = ft_strsplit(info[x], ',')))
			return (0);
		if (tmp[2] || !ft_atoi_strict(tmp[0]) || !ft_valid_hex(tmp[1]))
			return (0);
		m->backup[y][x].z = ft_atoi(tmp[0]);
		m->backup[y][x].c = ft_atoi_base(tmp[1] + 2, 16);
		m->backup[y][x].c_lock = 1;
		free_dbl(tmp, 2);
	}
	else
	{
		m->backup[y][x].z = ft_atoi(info[x]);
	}
	return (1);
}
