/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:26:07 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/08 17:07:31 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scalebetween(double unscaled_num, double old_max)
{
	double	new_min;
	double	new_max;
	double	result;

	new_min = -2;
	new_max = 2;
	result = (new_max - new_min) * (unscaled_num) / (old_max) + new_min;
	return (result);
}

int	generate_color(int i, int max_iterations)
{
	int	start_color;
	int	end_color;
	int	result;

	start_color = BLUE;
	end_color = YELLOW;
	result = (i * (end_color - start_color)) / max_iterations + start_color;
	return (result);
}

int	ft_close(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	exit(0);
}

void	msg_error(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}
