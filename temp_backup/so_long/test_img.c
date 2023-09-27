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

int	stop_win(int key, t_param *param)
{
	(void)key;
	mlx_destroy_image(param->mlx, param->img1);
	mlx_destroy_image(param->mlx, param->img2);
	mlx_destroy_window(param->mlx, param->win);
	printf("i stopped haha\n");
	exit (0);
}

int	main(void)
{
	t_param	param;

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 320, 320, "img_test_window");
	param.width = 40;
	param.height = 25;
	param.img1 = mlx_xpm_file_to_image(param.mlx, SL_TEST_IMG1, &param.width, &param.height);
// mlx changes width and height to the actual img values.
printf("width: old = %i, new = %i\n", 40, param.width);
printf("height: old = %i, new = %i\n", 25, param.width);
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

//printing img with negative x or y IT JUST WORKS!!
printf ("return test = %i\n", mlx_put_image_to_window(param.mlx, param.win, param.img1, 0, -10));

	mlx_key_hook(param.win, stop_win, (void *) &param);
	mlx_loop(param.mlx);
	printf("ait it aint possible to see this\n");
	mlx_destroy_image(param.mlx, param.img1);
	mlx_destroy_image(param.mlx, param.img2);
	mlx_destroy_window(param.mlx, param.win);
	return (13);
}
