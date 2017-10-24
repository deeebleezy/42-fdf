/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtuiasos <dentontui95@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 17:01:09 by dtuiasos          #+#    #+#             */
/*   Updated: 2017/10/09 22:45:21 by dtuiasos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>

# define THREAD_COUNT	16

# define WIN_WIDTH		2560.0
# define WIN_HEIGHT		1440.0
# define BORDER			0.85

# define YELLOW			0xffff00
# define RED			0xff0000
# define C_GRID			m->grid[y][x].c

# define COLOR_1		0x0000ff
# define COLOR_2		0x00ff00

# define TRANSLATE		8
# define ROT			0.1
# define MOUSE_SENS		0.1
# define ZOOM_IN		1.1
# define ZOOM_OUT		0.9
# define Z_SCALE_UP		1.2
# define Z_SCALE_DOWN	0.8

# define SX				0
# define SY 			1
# define ERR			2
# define ERR2			3
# define GRAD			4
# define HYPO			5
# define LVL			6
# define X1				7
# define Y1				8

typedef struct		s_coor
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	z1;
	double	z2;
	int		c1;
	int		c2;
	int		c_lock;
}					t_coor;

typedef struct		s_xyz
{
	double	x;
	double	y;
	double	z;
	int		c;
	int		c_lock:1;
}					t_xyz;

typedef struct		s_line
{
	struct s_line	*next;
	char			**info;
}					t_line;

typedef struct		s_img
{
	void			*ptr;
	int				*data;
	int				bpp;
	int				size;
	int				e;
}					t_img;

typedef struct		s_togs
{
	int				up:1;
	int				down:1;
	int				left:1;
	int				right:1;
	int				numpad_8:1;
	int				numpad_5:1;
	int				numpad_4:1;
	int				numpad_6:1;
	int				numpad_7:1;
	int				numpad_9:1;
	int				numpad_0:1;
	int				numpad_plus:1;
	int				numpad_minus:1;
	int				fn:1;
	int				bk_del:1;
	int				home:1;
	int				end:1;
	int				pg_up:1;
	int				pg_down:1;
	int				esc:1;
	int				mouse_left:1;
	int				mouse_right:1;
	int				mouse_wheel:1;
	int				mouse_wheel_up:1;
	int				mouse_wheel_down:1;
}					t_togs;

typedef struct		s_master
{
	t_xyz			**grid;
	t_xyz			**backup;
	t_line			*line;
	t_togs			*togs;
	t_img			*img;
	void			*mlx;
	void			*win;
	int				toggle:1;
	int				x_count;
	int				y_count;
	int				mouse_left_x;
	int				mouse_left_y;
	int				mouse_right_x;
	int				mouse_right_y;
	int				mouse_wheel_x;
	int				mouse_wheel_y;
	double			mid_x;
	double			mid_y;
	double			mid_z;
	double			bak_x;
	double			bak_y;
	double			bak_z;
	double			z_min;
	double			z_max;
}					t_m;

typedef struct		s_view
{
	t_m				*m;
	int				y;
	int				y_lim;
}					t_view;

void				pulse_pastel(t_m *m);
int					color_inc(int col_1, int col_2, int level);

int					build_grid(t_m *m);
int					add_node(t_m *m, char **line);
int					parse_data(t_m *m, char *buf);
int					first_step(t_m *m, char *arg);
void				draw_lines(t_m *m, int y, int y_lim);

int					expose_hook(t_m *m);
int					key_press_hook(int keycode, t_m *m);
void				key_num_rel(int keycode, t_m *m);
void				key_stretch_rel(int keycode, t_m *m);
int					key_release_hook(int keycode, t_m *m);
void				key_num_hook(int keycode, t_m *m);
void				key_stretch_hook(int keycode, t_m *m);
int					loop_hook(t_m *m);
void				esc_hook(t_m *m);

void				init_c(t_m *m);
int					init_z(t_m *m, char **info, int x, int y);
int					init_env(t_m *m);

int					mouse_press_hook(int keycode, int x, int y, t_m *m);
int					mouse_release_hook(int keycode, int x, int y, t_m *m);
int					mouse_motion_hook(int x, int y, t_m *m);
void				mouse_press2(int keycode, int x, int y, t_m *m);

void				rotate_z(t_m *m, double sin, double cos);
void				rotate_y(t_m *m, double sin, double cos);
void				rotate_x(t_m *m, double sin, double cos);
void				rotate_orbit(t_m *m, double x, double y);
void				rotate_obj(t_m *m, double x, double y, double z);

void				free_dbl(char **arr, int i);
void				scale_center(t_m *m, double i, double j, double k);
void				bresenham(t_img *img, t_coor c);
int					compute_code(double x, double y);
void				cohen_sutherland(t_img *img, t_coor c);
void				*threader(void *v);
void				start_draw(t_m *m);
void				color_bres(t_img *img, t_coor c, int *data, double *d);
void				coor_cohen(t_coor c, int ret_code, double ret[2]);
void				check_coor(t_coor *c, int *code1, int *code2, double *ret);
void				translate_xyz(t_m *m, double i, double j, double k);
void				reset_xyz(t_m *m);

#endif
