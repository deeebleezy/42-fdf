/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:16:23 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 18:28:44 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_x(t_m *m, double sin, double cos)
{
	double	bak_y;
	double	bak_z;
	int		x;
	int		y;

	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			bak_y = m->grid[y][x].y;
			bak_z = m->grid[y][x].z;
			m->grid[y][x].y = bak_y * cos - bak_z * sin;
			m->grid[y][x].z = bak_y * sin + bak_z * cos;
		}
	}
}
