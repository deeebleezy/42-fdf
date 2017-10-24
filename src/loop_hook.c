/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:14:58 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 21:31:10 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		loop_hook(t_m *m)
{
	(m->togs->up) ? translate_xyz(m, 0, -TRANSLATE, 0) : 0;
	(m->togs->down) ? translate_xyz(m, 0, TRANSLATE, 0) : 0;
	(m->togs->left) ? translate_xyz(m, -TRANSLATE, 0, 0) : 0;
	(m->togs->right) ? translate_xyz(m, TRANSLATE, 0, 0) : 0;
	(m->togs->numpad_8) ? rotate_obj(m, 1, 0, 0) : 0;
	(m->togs->numpad_5) ? rotate_obj(m, -1, 0, 0) : 0;
	(m->togs->numpad_4) ? rotate_obj(m, 0, -1, 0) : 0;
	(m->togs->numpad_6) ? rotate_obj(m, 0, 1, 0) : 0;
	(m->togs->numpad_7) ? rotate_obj(m, 0, 0, -1) : 0;
	(m->togs->numpad_9) ? rotate_obj(m, 0, 0, 1) : 0;
	(m->togs->numpad_plus) ? scale_center(m, ZOOM_IN, ZOOM_IN, 1) : 0;
	(m->togs->numpad_minus) ? scale_center(m, ZOOM_OUT, ZOOM_OUT, 1) : 0;
	(m->togs->fn) ? scale_center(m, ZOOM_IN, 1, 1) : 0;
	(m->togs->bk_del) ? scale_center(m, ZOOM_OUT, 1, 1) : 0;
	(m->togs->home) ? scale_center(m, 1, ZOOM_IN, 1) : 0;
	(m->togs->end) ? scale_center(m, 1, ZOOM_OUT, 1) : 0;
	(m->togs->pg_up) ? scale_center(m, 1, 1, Z_SCALE_UP) : 0;
	(m->togs->pg_down) ? scale_center(m, 1, 1, Z_SCALE_DOWN) : 0;
	(m->togs->numpad_0) ? reset_xyz(m) : 0;
	(m->togs->esc) ? esc_hook(m) : 0;
	start_draw(m);
	pulse_pastel(m);
	return (1);
}

void	esc_hook(t_m *m)
{
	mlx_destroy_window(m->mlx, m->win);
	exit(42);
}
