#include "so_long.h"

typedef struct s_param
{
	void	*mlx;
	void	*win;

	void	*img1;
	void	*img2;
	int		width;
	int		height;
}			t_param;

#define SL_TEST_IMG1 "./textures/empty.xpm"
#define SL_TEST_IMG2 "./textures/wall.xpm"

int	stop_win(t_param *param)
{
printf("destroying win...\n");
// ok segfault here for some reason...
	mlx_destroy_window(param->mlx, param->win);
printf("destroying img1...\n");
	mlx_destroy_image(param->mlx, param->img1);
printf("destroyed img1...\n");
	mlx_destroy_image(param->mlx, param->img2);
	return (0);
}

int	main(void)
{
	t_param	param;

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 320, 320, "img_test_window");
	param.width = 32;
	param.height = 32;
	param.img1 = mlx_xpm_file_to_image(param.mlx, SL_TEST_IMG1, &param.width, &param.height);
	param.img2 = mlx_xpm_file_to_image(param.mlx, SL_TEST_IMG2, &param.width, &param.height);

	int	j = 32;
	int	i = 0;
	while (i <= 320 - 32)
	{
		mlx_put_image_to_window(param.mlx, param.win, param.img2, i, 0);
		i += 32;
	}
	i = 0;
	while (i <= 320 - 32)
	{
		mlx_put_image_to_window(param.mlx, param.win, param.img2, i, 288);
		i += 32;
	}
	i = 32;
	while (i <= 288 - 32)
	{
		mlx_put_image_to_window(param.mlx, param.win, param.img2, 0, i);
		i += 32;
	}
	i = 32;
	while (i <= 288 - 32)
	{
		mlx_put_image_to_window(param.mlx, param.win, param.img2, 288, i);
		i += 32;
	}
	while (j <= 288 - 32)
	{
		i = 32;
		while (i <= 288 - 32)
		{
			mlx_put_image_to_window(param.mlx, param.win, param.img1, i, j);
			i += 32;
		}
		j += 32;
	}
	mlx_key_hook(param.win, stop_win, (void *) &param);
	mlx_loop(param.mlx);
}
