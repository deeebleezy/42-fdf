/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:55:10 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 18:22:33 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_draw(t_m *m)
{
	pthread_t	thread[THREAD_COUNT];
	t_view		v[THREAD_COUNT];
	int			y_lim;
	int			i;

	mlx_clear_window(m->mlx, m->win);
	m->img->ptr = mlx_new_image(m->mlx, WIN_WIDTH, WIN_HEIGHT);
	m->img->data = (int*)mlx_get_data_addr(m->img->ptr, &m->img->bpp,
			&m->img->size, &m->img->e);
	y_lim = m->y_count / THREAD_COUNT;
	i = -1;
	while (++i < THREAD_COUNT)
	{
		v[i].m = m;
		v[i].y = y_lim * i;
		v[i].y_lim = (i == THREAD_COUNT - 1) ? m->y_count : v[i].y + y_lim;
		pthread_create(&thread[i], NULL, threader, &v[i]);
	}
	i = -1;
	while (++i < THREAD_COUNT)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(m->mlx, m->win, m->img->ptr, 0, 0);
	mlx_destroy_image(m->mlx, m->img->ptr);
}
