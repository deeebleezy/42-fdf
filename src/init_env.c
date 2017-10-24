/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:11:52 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 16:04:45 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define SET_BCKUP(m, x, y) m->backup[y][x].x = x; m->backup[y][x].y = y

int			calc_zmin(t_m *m, int x, int y)
{
	return (m->z_min < m->backup[y][x].z);
}

int			calc_zmax(t_m *m, int x, int y)
{
	return (m->z_max > m->backup[y][x].z);
}

void		init_backup(t_m *m)
{
	m->bak_x = (m->x_count - 1) / 2.0;
	m->bak_y = (m->y_count - 1) / 2.0;
	m->bak_z = (m->z_min + m->z_max) / 2.0;
	init_c(m);
	reset_xyz(m);
}

int			init_env(t_m *m)
{
	t_line	*node;
	int		x;
	int		y;

	m->z_min = ~0u;
	m->z_max = -999999999.0;
	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			SET_BCKUP(m, x, y);
			if (!init_z(m, m->line->info, x, y))
				return (0);
			m->z_min = calc_zmin(m, x, y) ? m->z_min : m->backup[y][x].z;
			m->z_max = calc_zmax(m, x, y) ? m->z_max : m->backup[y][x].z;
		}
		node = m->line->next;
		free_dbl(m->line->info, m->x_count);
		free(m->line);
		m->line = node;
	}
	init_backup(m);
	return (1);
}
