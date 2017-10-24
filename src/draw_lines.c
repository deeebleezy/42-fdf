/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:55:41 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 16:39:48 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_coord_p1(int x, int y, t_coor *c, t_m *m)
{
	c->x1 = m->grid[y][x].x;
	c->y1 = m->grid[y][x].y;
	c->z1 = m->grid[y][x].z;
	c->c1 = m->grid[y][x].c;
}

void		set_coord_p2(int x, int y, t_coor *c, t_m *m)
{
	c->x2 = m->grid[y][x].x;
	c->y2 = m->grid[y][x].y;
	c->z2 = m->grid[y][x].z;
	c->c2 = m->grid[y][x].c;
	c->c_lock = m->grid[y][x].c_lock &&
		m->grid[y][x].c_lock ? 1 : 0;
}

void		draw_lines(t_m *m, int y, int y_lim)
{
	t_coor	coor;
	int		x;

	while (y < y_lim)
	{
		x = -1;
		while (++x < m->x_count)
		{
			set_coord_p1(x, y, &coor, m);
			if (x < m->x_count - 1)
			{
				set_coord_p2(x + 1, y, &coor, m);
				cohen_sutherland(m->img, coor);
			}
			if (y < (y_lim == m->y_count ? m->y_count - 1 : y_lim))
			{
				set_coord_p2(x, y + 1, &coor, m);
				cohen_sutherland(m->img, coor);
			}
		}
		++y;
	}
}
