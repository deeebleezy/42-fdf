/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:13:09 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 20:06:52 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_c(t_m *m)
{
	int grad;
	int level;
	int x;
	int y;

	grad = ((int)(m->z_max - m->z_min) / (10)) > 1 ?
		((int)(m->z_max - m->z_min) / (10)) : 1;
	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			if (!m->backup[y][x].c_lock)
			{
				level = ((m->backup[y][x].z - (int)m->z_min) / grad);
				if (m->backup[y][x].z == m->z_max || level > 10)
					level = 10;
				m->backup[y][x].c = (color_inc(COLOR_1, COLOR_2, level));
			}
		}
	}
}
