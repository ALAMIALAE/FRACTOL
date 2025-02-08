/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:26:16 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/08 16:19:27 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_equation(t_complex *z, t_complex *c)
{
	double	tmp;

	tmp = (z->real * z->real) - (z->i * z->i);
	z->i = 2 * z->real * z->i;
	z->real = tmp;
	z->real = z->real + c->real;
	z->i = z->i + c->i;
}

void	julia(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.real = (scalebetween(x, WIDTH) * fractol->keys.zoom)
		+ fractol->keys.shift_x;
	z.i = (scalebetween(y, HEIGHT) * fractol->keys.zoom)
		+ fractol->keys.shift_y;
	c.real = fractol->julia.real;
	c.i = fractol->julia.i;
	while (i < fractol->iterations)
	{
		julia_equation(&z, &c);
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
