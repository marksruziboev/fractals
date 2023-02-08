#include "fractol.h"

// z= initial point, z1 the final point

void triangle(t_data *data, t_vec z0, t_vec z1, t_vec z2, int color)
{
	
	my_line(data, z0, z1, color); 
	my_line(data, z1, z2, color); 
	my_line(data, z2, z0, color); 	
	
}// x(t) = x0 + T[= t*(x1 - x0)] y(t) = y0 *T*[(y1 - y0)/(x0 - x1)]

