
#include "fractol.h"

void    init(t_mlx *w)
{
	w->mlx = NULL;
	w->win = NULL;
	w->img = NULL;
	w->addr = NULL;
    w->color = NULL;
	w->bits_per_pixel = 0;
	w->line_length = 0;
	w->endian = 0;
	w->x = 0;
	w->y = 0;
	w->x_max = 0;
	w->y_max = 0;
	w->x_min = 0;
	w->y_min = 0;
	w->cx = 0;
	w->cy = 0;
}

void    img_wind(t_mlx *w, char *str) // type mlx
{     
    w->color = ft_calloc(OMEGA + 1, sizeof(int));
    if(!(w->color))
        exit_husseyin(1, w);
    w->mlx = mlx_init();
    if (!w->mlx)
        exit_husseyin(1, w);
	w->win = mlx_new_window(w->mlx, HEIGHT, HEIGHT, str);
    if (!w->win)
        exit_husseyin(1, w);
	w->img = mlx_new_image(w->mlx, HEIGHT, HEIGHT);
    if (!w->img)
        exit_husseyin(1, w);
    w->addr = mlx_get_data_addr(w->img, &(w->bits_per_pixel), &(w->line_length), &(w->endian));
    if (!w->addr)
        exit_husseyin(1, w);
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
