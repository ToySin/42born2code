#include "mlx_beta/mlx.h"

int main()
{
	void	*mlx1;
	void	*win1;
	void	*img1;
	void	*back_img1;
	void	*back_img_big;

	void	*test_img;

	int	width1 = 16;
	int height1 = 16;

	int	width2 = 320;
	int height2 = 320;

	mlx1 = mlx_init();
	win1 = mlx_new_window(mlx1, 512, 512, "mlx1-1");
	img1 = mlx_png_file_to_image(mlx1, "./asset/Free/Main Characters/Ninja Frog/Fall (32x32).png", &width1, &height1);
	back_img1 = mlx_png_file_to_image(mlx1, "./asset/Free/Background/Pink.png", &width1, &height1);
	back_img_big = mlx_png_file_to_image(mlx1, "./asset/Free/Background/Pink.png", &width2, &height2);

	mlx_put_image_to_window(mlx1, win1, back_img1, 0, 0);
	mlx_put_image_to_window(mlx1, win1, back_img_big, 100, 100);


	mlx_put_image_to_window(mlx1, win1, img1, 200, 200);
	mlx_put_image_to_window(mlx1, win1, img1, 100, 100);
	mlx_put_image_to_window(mlx1, win1, img1, 132, 100);

	mlx_loop(mlx1);

	return (0);
}
