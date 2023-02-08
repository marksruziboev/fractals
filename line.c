#include "fractol.h"

// z= initial point, z1 the final point
int abs(int n)
{
	if (n >= 0)
		return(n);
	else 
		return(-n);
}

int sign(int n)
{
	if (n >= 0)
		return (1);
	else 
		return(-1);
}
void	my_line(t_data *data, t_vec z0, t_vec z1, int color) 
{
	int t,c;

	t = 0;
	while (t < abs(z0.x - z1.x))// && t*abs(z1.y - z0.y)< abs(z0.y - z1.y))
	{
		my_mlx_pixel_put(data,  z0.x + t*sign(z1.x - z0.x), z0.y+t*(z1.y - z0.y)/(z1.x- z0.x), color);
		t++;
	}
	
}// x(t) = x0 + T[= t*(x1 - x0)] y(t) = y0 *T*[(y1 - y0)/(x0 - x1)]

