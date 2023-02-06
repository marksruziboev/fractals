#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "mlx_linux/mlx.h"


#define MLX_ERROR 1

typedef struct s_vect
{
	double x;
	double y;
} t_vect;

t_vect map(t_vect z, t_vect c)
{
	t_vect ret;

	ret.x = z.x*z.x - z.y*z.y + c.x;
	ret.y = 2*z.x*z.y + c.y;
	return ret;
}

int nic(t_vect z, t_vect c)
{
	t_vect next;
	
	next = map(z,c);
	int i = -1;
	while(++i < 1000)
	{
		next = map(next, c);
		if(next.x > 2 || next.x < -2 || next.y > 2 || next.y < -2)
		{
			return (0);
			break ;
		}
	}
	return (1);
}

typedef struct	s_data {
	void	*obe;
	char	*addr;
	void	*win_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void deyanx(t_vect c, t_data *data, int color)
{
	t_vect z;
	//t_vect c;
	t_vect next;
	
	z.x = 0;
	z.y = 0;
	
	double h = 0.001;
	
	while( c.y <= 1)
	{
		c.x = -2;
		while(c.x <= 1)
			{
				if (nic(z, c) > 0)
					my_mlx_pixel_put(data, floor(640*(c.x + 2)), floor(540*(c.y + 1)), color);
				c.x += h;
			}
		c.y += h;
	}
}



int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data img;
	t_vect d;
	//initial point
	d.x = -2;
	d.y = -1;

	mlx = mlx_init();
	if (mlx == NULL)
		return (MLX_ERROR);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello Marko!");
	if (mlx == NULL)
	{
		free(mlx);
		return (MLX_ERROR);
	}
	img.obe = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.obe, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	deyanx(d, &img, 0x00FF0000);
	my_mlx_pixel_put(&img, 480, 270, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.obe, 0, 0);
	mlx_loop(mlx);
	//mlx_loop_hook(mlx, &handle_no_event, &data);
	//mlx_key_hook(mlx_win, &key_input, &data);
	//mlx_hook(data.win_ptr, 17, 0, &click_destroy, &data);
}
