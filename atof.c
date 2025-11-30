/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-dri <aben-dri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:06:44 by aben-dri          #+#    #+#             */
/*   Updated: 2025/02/08 19:59:10 by aben-dri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	process_fraction(const char **str, double nb)
{
	double	fraction;

	fraction = 1.0;
	(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		fraction *= 0.1;
		nb += (**str - '0') * fraction;
		(*str)++;
	}
	return (nb);
}

double	process_integer(const char **str)
{
	double	nb;

	nb = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		nb = nb * 10.0 + (**str - '0');
		(*str)++;
	}
	return (nb);
}

int	process_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
	{
		(*str)++;
	}
	return (sign);
}

void	skip_whitespace(const char **str)
{
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
}

double	ft_atof(const char *str)
{
	double	nb;
	int		sign;

	skip_whitespace(&str);
	sign = process_sign(&str);
	nb = process_integer(&str);
	if (*str == '.')
		nb = process_fraction(&str, nb);
	return (nb * sign);
}
