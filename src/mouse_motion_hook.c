/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:13:49 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 15:04:55 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_motion_hook(int x, int y, t_m *m)
{
	if (m->togs->mouse_left)
	{
		translate_xyz(m, x - m->mouse_left_x, y - m->mouse_left_y, 0);
		m->mouse_left_x += x - m->mouse_left_x;
		m->mouse_left_y += y - m->mouse_left_y;
	}
	if (m->togs->mouse_right)
	{
		rotate_obj(m, -(y - m->mouse_right_y) * MOUSE_SENS,
				(x - m->mouse_right_x) * MOUSE_SENS, 0);
		m->mouse_right_x += x - m->mouse_right_x;
		m->mouse_right_y += y - m->mouse_right_y;
	}
	if (m->togs->mouse_wheel)
		rotate_orbit(m, -(y - m->mouse_wheel_y) * MOUSE_SENS,
				(x - m->mouse_wheel_x) * MOUSE_SENS);
	if (m->toggle)
		start_draw(m);
	return (1);
}
