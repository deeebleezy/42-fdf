/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:14:27 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 22:39:23 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press_hook(int keycode, int x, int y, t_m *m)
{
	if (keycode == 1 && x >= 0 && y >= 0 && x <= WIN_WIDTH && y <= WIN_HEIGHT)
	{
		if (!m->togs->mouse_left)
		{
			m->mouse_left_x = x;
			m->mouse_left_y = y;
		}
		m->togs->mouse_left = 1;
	}
	if (keycode == 2 && x >= 0 && y >= 0 && x <= WIN_WIDTH && y <= WIN_HEIGHT)
	{
		if (!m->togs->mouse_right)
		{
			m->mouse_right_x = x;
			m->mouse_right_y = y;
		}
		m->togs->mouse_right = 1;
	}
	if (keycode >= 3 && keycode <= 5)
		mouse_press2(keycode, x, y, m);
	return (1);
}

void	mouse_press2(int keycode, int x, int y, t_m *m)
{
	if (keycode == 3)
	{
		if (!m->togs->mouse_wheel)
		{
			m->mouse_wheel_x = x;
			m->mouse_wheel_y = y;
		}
		m->togs->mouse_wheel = 1;
	}
	if (keycode == 4)
	{
		start_draw(m);
	}
	if (keycode == 5)
	{
		start_draw(m);
	}
	return ;
}
