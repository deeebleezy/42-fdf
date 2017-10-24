/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:15:39 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 21:16:19 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_obj(t_m *m, double x, double y, double z)
{
	double	temp[3];

	temp[0] = m->mid_x;
	temp[1] = m->mid_y;
	temp[2] = m->mid_z;
	translate_xyz(m, -m->mid_x, -m->mid_y, -m->mid_z);
	if (x)
		rotate_x(m, sin(x * 0.1), cos(x * 0.1));
	if (y)
		rotate_y(m, sin(y * 0.1), cos(y * 0.1));
	if (z)
		rotate_z(m, sin(z * 0.1), cos(z * 0.1));
	translate_xyz(m, temp[0], temp[1], temp[2]);
	m->toggle = 1;
}
