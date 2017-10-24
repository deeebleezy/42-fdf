/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_xyz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:17:17 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/04 21:21:10 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_xyz(t_m *m, double i, double j, double k)
{
	int x;
	int y;

	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			m->grid[y][x].x += i;
			m->grid[y][x].y += j;
			m->grid[y][x].z += k;
		}
	}
	m->mid_x += i;
	m->mid_y += j;
	m->mid_z += k;
	m->toggle = 1;
}
