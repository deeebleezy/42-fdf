/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:15:48 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 20:36:03 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press_hook(int keycode, t_m *m)
{
	if (keycode >= 123 && keycode <= 126)
	{
		if (keycode == 126)
			m->togs->up = 1;
		else if (keycode == 125)
			m->togs->down = 1;
		else if (keycode == 123)
			m->togs->left = 1;
		else if (keycode == 124)
			m->togs->right = 1;
	}
	if (keycode == 69 || keycode == 78 || (keycode >= 86 && keycode <= 92))
		key_num_hook(keycode, m);
	if ((keycode >= 115 && keycode <= 121) || keycode == 279 ||
			keycode == 53 || keycode == 83)
		key_stretch_hook(keycode, m);
	return (1);
}

void	key_num_hook(int keycode, t_m *m)
{
	if (keycode == 91)
		m->togs->numpad_8 = 1;
	else if (keycode == 87)
		m->togs->numpad_5 = 1;
	else if (keycode == 88)
		m->togs->numpad_6 = 1;
	else if (keycode == 86)
		m->togs->numpad_4 = 1;
	else if (keycode == 89)
		m->togs->numpad_7 = 1;
	else if (keycode == 92)
		m->togs->numpad_9 = 1;
	else if (keycode == 69)
		m->togs->numpad_plus = 1;
	else if (keycode == 78)
		m->togs->numpad_minus = 1;
	return ;
}

void	key_stretch_hook(int keycode, t_m *m)
{
	if (keycode == 279)
		m->togs->fn = 1;
	else if (keycode == 117)
		m->togs->bk_del = 1;
	else if (keycode == 115)
		m->togs->home = 1;
	else if (keycode == 119)
		m->togs->end = 1;
	else if (keycode == 116)
		m->togs->pg_up = 1;
	else if (keycode == 121)
		m->togs->pg_down = 1;
	else if (keycode == 82)
		m->togs->numpad_0 = 1;
	else if (keycode == 53)
		m->togs->esc = 1;
	return ;
}
