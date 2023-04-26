/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelasam <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:18:18 by eelasam           #+#    #+#             */
/*   Updated: 2023/03/21 18:10:32 by eelasam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_putpixel(t_p *p, int x, int y, int color)
{
	char	*dst;

	dst = p->data + (y * p->line_len + x * (p->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	move(int keycode, t_p *p)
{
	ft_esc (keycode, p);
	if (keycode == LEFT_KEY)
		p->x += 0.03;
	if (keycode == RIGHT_KEY)
		p->x -= 0.03;
	if (keycode == UP_KEY)
		p->y += 0.03;
	if (keycode == DOWN_KEY)
		p->y -= 0.03;
	mlx_clear_window(p->ptr, p->win);
	if (!ft_strcmp(p->fractal, "julia") || !ft_strcmp(p->fractal, "first_julia")
		|| !ft_strcmp(p->fractal, "second_julia"))
		julia(p->fractal, p);
	if (!ft_strcmp(p->fractal, "mandelbrot"))
		mandelbrot(p);
	if (!ft_strcmp(p->fractal, "burning_ship"))
		burning_ship(p);
	mlx_put_image_to_window(p->ptr, p->win, p->img, p->x, p->y);
	return (0);
}

int	zoom(int keycode, int x, int y, t_p *p)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_DOWN || keycode == MOUSE_UP)
	{
		if (keycode == MOUSE_DOWN)
			p->zoom /= 0.5;
		else
			p->zoom *= 0.5;
	}
	mlx_clear_window(p->ptr, p->win);
	if (!ft_strcmp(p->fractal, "julia") || !ft_strcmp(p->fractal, "first_julia")
		|| !ft_strcmp(p->fractal, "second_julia"))
		julia(p->fractal, p);
	if (!ft_strcmp(p->fractal, "mandelbrot"))
		mandelbrot(p);
	if (!ft_strcmp(p->fractal, "burning_ship"))
		burning_ship(p);
	mlx_put_image_to_window(p->ptr, p->win, p->img, 0, 0);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (src[y] != '\0')
		y++;
	dest = malloc(y + 1);
	if (dest == NULL)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
