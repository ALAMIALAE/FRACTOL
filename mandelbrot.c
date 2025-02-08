/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:00:30 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/08 16:21:23 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_equation(t_complex *z, t_complex *c)
{
	double	tmp;

	tmp = (z->real * z->real) - (z->i * z->i);
	z->i = 2 * z->real * z->i;
	z->real = tmp;
	z->real = z->real + c->real;
	z->i = z->i + c->i;
}

void	mandelbrot(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	color = 0;
	i = 0;
	z.real = 0.0;
	z.i = 0.0;
	c.real = (scalebetween(x, WIDTH) * fractol->keys.zoom)
		+ fractol->keys.shift_x;
	c.i = (scalebetween(y, HEIGHT) * fractol->keys.zoom)
		+ fractol->keys.shift_y;
	while (i < fractol->iterations)
	{
		mandelbrot_equation(&z, &c);
		if ((z.real * z.real) + (z.i * z.i) > 4)
		{
			color = generate_color(i, fractol->iterations);
			my_mlx_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(x, y, &fractol->img, BLACK);
}
