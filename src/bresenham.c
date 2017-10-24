/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:46:43 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 21:25:03 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		bresenham(t_img *img, t_coor c)
{
	int		data[9];
	double	d[2];

	d[0] = fabs(c.x2 - c.x1);
	d[1] = fabs(c.y2 - c.y1);
	data[SX] = (c.x1 < c.x2) ? 1 : 0;
	data[SY] = (c.y1 < c.y2) ? 1 : 0;
	data[ERR] = (d[0] > d[1] ? d[0] : -d[1]) / 2;
	data[X1] = c.x1;
	data[Y1] = c.y1;
	data[HYPO] = hypot(d[0], d[1]);
	if ((int)(data[HYPO] / (10)) > 1)
		data[GRAD] = (int)(data[HYPO] / (10));
	else
		data[GRAD] = 1;
	color_bres(img, c, data, d);
}

int			calc_color(t_img *img, t_coor c)
{
	return ((int)c.x1 + (int)c.y1 * img->size / 4);
}

void		color_bres(t_img *img, t_coor c, int *data, double *d)
{
	while (!((!(data[SX] && c.x1 <= c.x2) || (data[SX] && c.x1 >= c.x2)) &&
			((!data[SY] && c.y1 <= c.y2) || (data[SY] && c.y1 >= c.y2))))
	{
		if (c.c1 == c.c2)
			img->data[calc_color(img, c)] = c.c1;
		else
		{
			data[LVL] = (hypot(c.x1 - data[X1], c.y1 - data[Y1]) / data[GRAD]);
			img->data[calc_color(img, c)] = color_inc(c.c1, c.c2, data[LVL]);
		}
		data[ERR2] = data[ERR];
		if (data[ERR2] > -d[0])
		{
			data[ERR] -= d[1];
			(data[SX]) ? (c.x1 += 1) : (c.x1 -= 1);
		}
		if (data[ERR2] < d[1])
		{
			data[ERR] += d[0];
			(data[SY]) ? (c.y1 += 1) : (c.y1 -= 1);
		}
	}
}
