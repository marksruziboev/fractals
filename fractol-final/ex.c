#include "mlx.h"

int main()
{
    // Initialize the minilibx library and create a window
    void *mlx_ptr = mlx_init();
    void *win_ptr = mlx_new_window(mlx_ptr, 640, 480, "My Window");

    // Generate a color with red=255, green=0, blue=0, alpha=255 (opaque red)
    int red = 255;
    int green = 0;
    int blue = 0;
    int alpha = 255;
    int color = mlx_get_color_value(mlx_ptr, (alpha << 24) | (red << 16) | (green << 8) | blue);

    // Use the color to draw a pixel on the window
    mlx_pixel_put(mlx_ptr, win_ptr, 320, 240, color);

    // Loop to keep the window open
    mlx_loop(mlx_ptr);

    return 0;
}
