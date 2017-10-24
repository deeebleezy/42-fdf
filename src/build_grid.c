/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:11:33 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 14:42:56 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	build_grid(t_m *m)
{
	int i;

	if (!(m->grid = (t_xyz **)ft_memalloc(sizeof(t_xyz *) * m->y_count)) ||
		!(m->backup = (t_xyz **)ft_memalloc(sizeof(t_xyz *) * m->y_count)))
		return (0);
	i = -1;
	while (++i < m->y_count)
		if (!(m->grid[i] = (t_xyz *)ft_memalloc(sizeof(t_xyz) * m->x_count)) ||
			!(m->backup[i] = (t_xyz *)ft_memalloc(sizeof(t_xyz) * m->x_count)))
			return (0);
	return (init_env(m) ? 1 : 0);
}
