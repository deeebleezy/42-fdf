/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:15:26 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 20:44:45 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_release_hook(int keycode, t_m *m)
{
	if (keycode >= 123 && keycode <= 126)
	{
		if (keycode == 126)
			m->togs->up = 0;
		else if (keycode == 125)
			m->togs->down = 0;
		else if (keycode == 123)
			m->togs->left = 0;
		else if (keycode == 124)
			m->togs->right = 0;
	}
	if (keycode == 69 || keycode == 78 || (keycode >= 86 && keycode <= 92))
		key_num_rel(keycode, m);
	if ((keycode >= 115 && keycode <= 121) || keycode == 279 ||
				keycode == 53 || keycode == 83)
		key_stretch_rel(keycode, m);
	return (0);
}

void	key_num_rel(int keycode, t_m *m)
{
	if (keycode == 91)
		m->togs->numpad_8 = 0;
	else if (keycode == 87)
		m->togs->numpad_5 = 0;
	else if (keycode == 88)
		m->togs->numpad_6 = 0;
	else if (keycode == 86)
		m->togs->numpad_4 = 0;
	else if (keycode == 89)
		m->togs->numpad_7 = 0;
	else if (keycode == 92)
		m->togs->numpad_9 = 0;
	else if (keycode == 69)
		m->togs->numpad_plus = 0;
	else if (keycode == 78)
		m->togs->numpad_minus = 0;
	return ;
}

void	key_stretch_rel(int keycode, t_m *m)
{
	if (keycode == 279)
		m->togs->fn = 0;
	else if (keycode == 117)
		m->togs->bk_del = 0;
	else if (keycode == 115)
		m->togs->home = 0;
	else if (keycode == 119)
		m->togs->end = 0;
	else if (keycode == 116)
		m->togs->pg_up = 0;
	else if (keycode == 121)
		m->togs->pg_down = 0;
	else if (keycode == 82)
		m->togs->numpad_0 = 0;
	else if (keycode == 53)
		m->togs->esc = 0;
	return ;
}
