/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulse_pastel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:38:49 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 22:37:03 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pulse_pastel(t_m *m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < m->y_count)
	{
		x = -1;
		while (++x < m->x_count)
		{
			if (!m->grid[y][x].c_lock)
			{
				if (((C_GRID ^ YELLOW) < 0x100) && (C_GRID & 0xff) > 0)
					C_GRID -= 1;
				else if ((C_GRID ^ RED) < 0x10000 && (C_GRID & 0xff) < 0xff)
					C_GRID -= 0xff;
				else if ((C_GRID & RED) && (C_GRID & 0xff00) < 0xff00)
					C_GRID -= 0xff00;
				else if ((C_GRID & RED) < 0xff0000)
					C_GRID += 0xffff;
				else
					C_GRID = 0xffffff;
			}
		}
	}
}
