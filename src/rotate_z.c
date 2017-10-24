/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:16:58 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 18:27:43 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_z(t_m *m, double sin, double cos)
{
	double	bak_x;
	double	bak_y;
	int		x;
	int		y;

	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			bak_x = m->grid[y][x].x;
			bak_y = m->grid[y][x].y;
			m->grid[y][x].x = bak_x * cos - bak_y * sin;
			m->grid[y][x].y = bak_x * sin + bak_y * cos;
		}
	}
}
