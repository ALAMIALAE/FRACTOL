/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:21:45 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/08 16:17:40 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		msg_error("error");
	fractol->mlx_win = mlx_new_window(fractol->mlx, HEIGHT, WIDTH,
			"My Fractol");
	if (fractol->mlx_win == NULL)
		msg_error("error");
	fractol->img.img = mlx_new_image(fractol->mlx, HEIGHT, WIDTH);
	if (fractol->img.img == NULL)
	{
		mlx_destroy_image(fractol->mlx, fractol->img.img);
		msg_error("error");
	}
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	mlx_mouse_hook(fractol->mlx_win, mouse_hook, fractol);
	mlx_key_hook(fractol->mlx_win, key_hook, fractol);
	mlx_hook(fractol->mlx_win, DESTROYNOTIFY, 0, ft_close, fractol);
}
