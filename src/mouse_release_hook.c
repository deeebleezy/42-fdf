/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:14:00 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 18:31:56 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_release_hook(int keycode, int x, int y, t_m *m)
{
	(void)x;
	(void)y;
	if (keycode == 1)
		m->togs->mouse_left = 0;
	if (keycode == 2)
		m->togs->mouse_right = 0;
	if (keycode == 3)
		m->togs->mouse_wheel = 0;
	return (1);
}
