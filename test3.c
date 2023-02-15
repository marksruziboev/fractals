#include "fractol.h"

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	key_input(int keysym, t_data *data) // esc to close the window
{
	if (keysym == XK_Escape)
		free(data-> addr);
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);	
	return (0);
}

int	click_destroy(t_data *data)// click to close the window
{
	write(1,"Sari kafayi basi",16);
	//free(data-> addr);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	return (0);
}
