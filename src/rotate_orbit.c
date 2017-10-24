/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_orbit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:15:59 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 18:29:09 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_orbit(t_m *m, double x, double y)
{
	double	temp_z;

	temp_z = -m->mid_z;
	translate_xyz(m, -m->mouse_wheel_x, -m->mouse_wheel_y, -m->mid_z);
	if (x)
		rotate_x(m, sin(x * ROT * MOUSE_SENS), cos(x * ROT * MOUSE_SENS));
	if (y)
		rotate_y(m, sin(y * ROT * MOUSE_SENS), cos(y * ROT * MOUSE_SENS));
	translate_xyz(m, m->mouse_wheel_x, m->mouse_wheel_y, temp_z);
	m->toggle = 1;
}
