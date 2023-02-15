
#include "fractol.h"


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
	while(++i < 50)
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

void deyanx(t_vect c, t_data *data, int color)
{
	t_vect z;
	t_vect next;
	int p;
	int q;
	
	z.x = 0;
	z.y = 0;
	
	double h = 0.001;
	
	while( c.y <= 1)
	{
		c.x = -2;
		while(c.x <= 1)
			{
				p = floor(400*(c.x + 2));
				q = HEIGHT- floor(400*(c.y + 1));
				if (nic(z, c) > 0)
					my_mlx_pixel_put(data, p, q, color);
				c.x += h;
			}
		c.y += h;
	}
}


void jeyanx(t_vect c, t_data *data, int color)
{
	t_vect z;
	t_vect next;
	
	z.x = -2;
	z.y = -2;
	
	double h = 0.001;
	
	while( z.y <= 2)
	{
		z.x = -2;
		while(z.x <= 2)
			{
				if (nic(z, c) > 0)
					my_mlx_pixel_put(data, floor(200*z.x + 600), HEIGHT-floor(200*z.y+400), color);
				z.x += h;
			}
		z.y += h;
	}
}

