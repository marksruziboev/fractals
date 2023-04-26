
#include "fractol.h"

void    img_wind(t_mlx *w, char *str) // type mlx
{
    w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, HEIGHT, HEIGHT, str);
	w->img = mlx_new_image(w->mlx, HEIGHT, HEIGHT);
    w->addr = mlx_get_data_addr(w->img, &(w->bits_per_pixel), &(w->line_length), &(w->endian));
}

void    my_mlx_pixel_put(t_mlx *w, t_ivec *p, int color)
{
	char	*dst;

	dst = w->addr + (p->y * w->line_length + p->x * (w->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

void    plot_fractal(t_mlx *w)
{
    /*if(!ft_strncmp(ft_tolower(str), "julia", 5))
        julia(w, str);*/
    mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
}
