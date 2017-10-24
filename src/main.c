/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:10:41 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 20:35:21 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_m	m;

	ft_bzero(&m, sizeof(t_m));
	if (ac != 2 || !first_step(&m, av[1]))
		return (write(2, "Error\n", 6) - 6);
	if (m.x_count && m.y_count)
	{
		m.mlx = mlx_init();
		m.win = mlx_new_window(m.mlx, WIN_WIDTH, WIN_HEIGHT, av[1]);
		m.togs = (t_togs*)ft_memalloc(sizeof(t_togs));
		m.img = (t_img*)ft_memalloc(sizeof(t_img));
		mlx_hook(m.win, 12, 0, expose_hook, &m);
		mlx_hook(m.win, 2, 0, key_press_hook, &m);
		mlx_hook(m.win, 3, 0, key_release_hook, &m);
		mlx_hook(m.win, 4, 0, mouse_press_hook, &m);
		mlx_hook(m.win, 5, 0, mouse_release_hook, &m);
		mlx_hook(m.win, 6, 0, mouse_motion_hook, &m);
		mlx_loop_hook(m.mlx, loop_hook, &m);
		mlx_loop(m.mlx);
	}
	return (1);
}
