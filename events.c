/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:32:01 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/08 20:01:46 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractol *fractol, int x, int y, int zoom_type)
{
	double	zoom_factor;
	double	old_x;
	double	old_y;
	double	new_x;
	double	new_y;

	if (!fractol)
		return ;
	if (zoom_type == 1)
		zoom_factor = 1.2;
	else if (zoom_type == -1)
		zoom_factor = 1 / 1.2;
	else
		return ;
	if (fractol->keys.zoom <= 0)
		fractol->keys.zoom = 1;
	old_x = (x - (WIDTH / 2)) / fractol->keys.zoom + fractol->offset_x;
	old_y = (y - (HEIGHT / 2)) / fractol->keys.zoom + fractol->offset_y;
	fractol->keys.zoom *= zoom_factor;
	new_x = (x - (WIDTH / 2)) / fractol->keys.zoom + fractol->offset_x;
	new_y = (y - (HEIGHT / 2)) / fractol->keys.zoom + fractol->offset_y;
	fractol->offset_x += old_x - new_x;
	fractol->offset_y += old_y - new_y;
}

int	mouse_hook(int mouse_code, int x, int y, t_fractol *fractol)
{
	if (mouse_code == MOUSE_SCROLL_UP)
		zoom(fractol, x, y, 1);
	else if (mouse_code == MOUSE_SCROLL_DOWN)
		zoom(fractol, x, y, -1);
	fractol_render(fractol);
	return (0);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(fractol->mlx, fractol->mlx_win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 113)
	{
		fractol->iterations += 10;
	}
	fractol_render(fractol);
	return (0);
}
