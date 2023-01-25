#include "mlx_linux/mlx.h"
#include <stdio.h>
#include <math.h>

typedef struct t_vect
{
	double x;
	double y;
} vect;

vect map(vect z, vect c)
{
	vect ret;

	ret.x = z.x*z.x - z.y*z.y + c.x;
	ret.y = 2*z.x*z.y + c.y;
	return ret;
}

int nic(vect z, vect c)
{
	vect next;
	
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
int	main(void)
{
	//void	*mlx;
	//mlx = mlx_init();
	vect z;
	vect c;
	vect next;
	int i = 0;

	z.x = 0;
	z.y = 0;

	c.x = -2;
	c.y = -1;
	
	double h = 0.03;
	
	while( c.y <= 1)
	{
		c.x = -2;
		while(c.x <= 1)
			{
				if (nic(z, c) > 0)
					printf("#");
				else 
					printf(" ");
				c.x += h;
			}
			printf("\n");
		c.y += h;
	}	

/*	next = map(z,c);
	i = -1;
	while(++i < 10)
	{
		next = map(next, c);
		printf("%f %f \n", next.x, next.y);
	}
	printf("%f %f \n", next.x, next.y);
	
*/		
	
}
