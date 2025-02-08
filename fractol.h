/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:24:48 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/08 16:24:53 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 800

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define KEY_ESC 65307

# define MANDELBROT 1
# define JULIA 2

# define BLACK 0x000000
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00

# define DESTROYNOTIFY 17

typedef struct s_keys
{
	double		shift_x;
	double		shift_y;
	double		zoom;
}				t_keys;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_complex
{
	double		real;
	double		i;
}				t_complex;

typedef struct s_fractol
{
	int			x;
	int			y;
	double		offset_x;
	double		offset_y;
	int			color;
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_keys		keys;
	t_complex	julia;
	int			iterations;
	t_complex	c;
	char		*name;
}				t_fractol;

void			my_mlx_pixel_put(int x, int y, t_img *img, int color);
int				generate_color(int i, int max_iterations);
void			mandelbrot_equation(t_complex *z, t_complex *c);
void			mandelbrot(int x, int y, t_fractol *fractol);
void			julia_equation(t_complex *z, t_complex *c);
void			julia(int x, int y, t_fractol *fractol);
double			scalebetween(double unscaled_num, double old_max);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
double			ft_atof(const char *str);
int				key_hook(int keycode, t_fractol *fractol);
void			fractol_render(t_fractol *fractol);
void			msg_error(char *err);
int				ft_close(t_fractol *fractol);
void			fractol_mlx(t_fractol *fractol);
void			zoom(t_fractol *fractal, int x, int y, int zoom_type);
int				mouse_hook(int mouse_code, int x, int y, t_fractol *fractal);

#endif