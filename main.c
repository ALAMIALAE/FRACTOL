/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:26:41 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/08 17:01:13 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->addr + offset) = color;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while ((ss1[i] || ss2[i]) && i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

void	checks(void)
{
	if (HEIGHT < 0 || WIDTH < 0 || HEIGHT > 2000 || WIDTH > 2000)
		msg_error("error");
	if (HEIGHT != WIDTH)
		msg_error("error");
}

void	handle_julia(int argc, char **argv, t_fractol *fractol)
{
	if (argc == 4 && !ft_strncmp(argv[1], "Julia", 5))
	{
		fractol->julia.real = ft_atof(argv[2]);
		fractol->julia.i = ft_atof(argv[3]);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 10)) || (argc == 4
			&& !ft_strncmp(argv[1], "Julia", 5)))
	{
		checks();
		fractol.name = argv[1];
		fractol.keys.zoom = 1.0;
		fractol.x = 0;
		fractol.y = 0;
		fractol.color = 0xFCBE11;
		fractol.offset_x = -2.0;
		fractol.offset_y = -1.5;
		fractol.keys.shift_x = 0.0;
		fractol.keys.shift_y = 0.0;
		fractol.iterations = 50;
		handle_julia(argc, argv, &fractol);
		fractol_mlx(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
		msg_error("error");
	return (0);
}
