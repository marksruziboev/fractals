#include <stdlib.h>
#include <unistd.h>
#include "mlx_linux/mlx.h"
#include <X11/keysym.h>


# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
#define MLX_ERROR 1



typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	key_input(int keysym, t_data *data) // esc to close the window
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	
	return (0);
}

int	click_destroy(t_data *data)// click to close the window
{
	write(1,"Sari kafayi basi",16);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
/*
int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	
	//img_ptr = mlx_new_image(mlx_ptr, WINDOW_WIDTH, 
	//WINDOW_HEIGHT);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, 
	WINDOW_HEIGHT, "My first window!");
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x, y);
	
	
	
	

	// Setup hooks  
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &key_input, &data);
	mlx_hook(data.win_ptr, 17, 0, &click_destroy, &data);
	mlx_loop(data.mlx_ptr);

	// we will exit the loop if there's no window left, and execute this code 
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return(0);
}*/
