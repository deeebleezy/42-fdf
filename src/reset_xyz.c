/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_xyz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:15:22 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 17:26:27 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_xyz(t_m *m)
{
	int x;
	int y;
	int	gap;

	gap = (m->x_count > m->y_count ? WIN_WIDTH / (m->x_count - 1) :
			WIN_HEIGHT / (m->y_count - 1)) * BORDER;
	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			m->grid[y][x].x = m->backup[y][x].x;
			m->grid[y][x].y = m->backup[y][x].y;
			m->grid[y][x].z = m->backup[y][x].z;
			m->grid[y][x].c = m->backup[y][x].c;
			m->grid[y][x].c_lock = m->backup[y][x].c_lock;
		}
	}
	m->mid_x = m->bak_x;
	m->mid_y = m->bak_y;
	m->mid_z = m->bak_z;
	scale_center(m, gap, gap, 10);
	translate_xyz(m, WIN_WIDTH / 2 - m->mid_x, WIN_HEIGHT / 2 - m->mid_y, 0);
	m->toggle = 1;
}
