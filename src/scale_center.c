/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_center.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:18:04 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 18:30:26 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_center(t_m *m, double i, double j, double k)
{
	int	x;
	int	y;

	x = -1;
	while (++x < m->x_count)
	{
		y = -1;
		while (++y < m->y_count)
		{
			if (i > 0)
				m->grid[y][x].x = m->mid_x + (i * (m->grid[y][x].x - m->mid_x));
			if (j > 0)
				m->grid[y][x].y = m->mid_y + (j * (m->grid[y][x].y - m->mid_y));
			if (k > 0)
			{
				m->grid[y][x].z *= k;
			}
		}
	}
	m->toggle = 1;
}
