/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:16:42 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 18:28:15 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_y(t_m *m, double sin, double cos)
{
	double	bak_x;
	double	bak_z;
	int		x;
	int		y;

	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			bak_x = m->grid[y][x].x;
			bak_z = m->grid[y][x].z;
			m->grid[y][x].x = bak_x * cos + bak_z * sin;
			m->grid[y][x].z = -(bak_x * sin) + bak_z * cos;
		}
	}
}
