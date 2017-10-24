/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cohen_sutherland.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:14:00 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 15:38:19 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		cohen_sutherland(t_img *img, t_coor c)
{
	int		code1;
	int		code2;
	int		ret_code;
	double	ret[2];

	code1 = compute_code(c.x1, c.y1);
	code2 = compute_code(c.x2, c.y2);
	while (1)
	{
		if (!code1 && !code2)
		{
			bresenham(img, c);
			break ;
		}
		else if (code1 & code2)
			break ;
		else
		{
			ret_code = code1 ? code1 : code2;
			coor_cohen(c, ret_code, ret);
			check_coor(&c, &code1, &code2, ret);
		}
	}
}

void		check_coor(t_coor *c, int *code1, int *code2, double *ret)
{
	if (*code1)
	{
		c->x1 = ret[0];
		c->y1 = ret[1];
		*code1 = compute_code(c->x1, c->y1);
	}
	else
	{
		c->x2 = ret[0];
		c->y2 = ret[1];
		*code2 = compute_code(c->x2, c->y2);
	}
}

void		coor_cohen(t_coor c, int ret_code, double ret[2])
{
	if (ret_code & 8)
	{
		ret[0] = c.x1 + (c.x2 - c.x1) * (WIN_HEIGHT - 1 - c.y1) / (c.y2 - c.y1);
		ret[1] = WIN_HEIGHT - 1;
	}
	else if (ret_code & 4)
	{
		ret[0] = c.x1 + (c.x2 - c.x1) * (0 - c.y1) / (c.y2 - c.y1);
		ret[1] = 0;
	}
	else if (ret_code & 2)
	{
		ret[0] = WIN_WIDTH - 1;
		ret[1] = c.y1 + (c.y2 - c.y1) * (WIN_WIDTH - 1 - c.x1) / (c.x2 - c.x1);
	}
	else if (ret_code & 1)
	{
		ret[0] = 0;
		ret[1] = c.y1 + (c.y2 - c.y1) * (0 - c.x1) / (c.x2 - c.x1);
	}
}
