/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:26:28 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/08 16:17:07 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_render(t_fractol *fractol)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (ft_strncmp(fractol->name, "Mandelbrot", 10) == 0)
				mandelbrot(i, j, fractol);
			else if (ft_strncmp(fractol->name, "Julia", 5) == 0)
				julia(i, j, fractol);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img, 0,
		0);
}
