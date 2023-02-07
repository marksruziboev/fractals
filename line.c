#include "fractol.h"

// z= initial point, z1 the final point
void	my_line(t_data *data, t_vec z0, t_vec z1, int color) 
{
	int t,c;
	
	t = 0;
	while (t <= abs(z0.x,z1.x))
	{
		c = t*abs(z1.y,z0.y)/abs(z1.x, z0.x);
		my_mlx_pixel_put(&img,  z0.x + t, z0.y + c, 0x00FF0000);
		t++;
	}
}// x(t) = x0 + T[= t*(x1 - x0)] y(t) = y0 *T*[(y1 - y0)/(x0 - x1)]

