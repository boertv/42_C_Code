#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

#define SP_Y 20
#define SP_X 15

typedef struct s_param
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}			t_param;

int	create_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// put a square of xi by xy pixels
void	put_pxs(t_param *param, int x, int y, int xi, int yi, int color)
{
	int	j;

	while (yi--)
	{
		j = xi;
		while (j--)
			mlx_pixel_put(param->mlx, param->win, x + j, y + yi, color);
	}
}

void	put_string(t_param *param, int color, char *s)
{
	mlx_string_put(param->mlx, param->win, param->x, param->y, color, s);
	if (param->x < 50)
		param->x += SP_X;
	else
	{
		param->x = 5;
		param->y += SP_Y;
	}
}

int	del_char(t_param *param)
{
	if (param->x < 6)
	{
		if (param->y < 6)
		return (1);
		param->y -= SP_Y;
		param->x = 50;
	}
	else
		param->x -= SP_X;
	put_pxs(param, param->x, param->y + 5, SP_X, SP_Y, 0);
	return (0);
}

int	event_key(int key, t_param *param)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit (0);
	}
	else if (key == KEY_RTRN)
		del_char(param);
	else if (key == KEY_TAB)
	{
		mlx_clear_window(param->mlx, param->win);
		param->x = 5;
		param->y = 0;
	}
	else if (key == KEY_ENTR)
	{
		param->x = 5;
		param->y += SP_Y;
	}
	else if (key == 18)
		put_string(param, create_color(0, 250, 250, 250), "1");
	else if (key == 29)
		put_string(param, create_color(0, 250, 250, 250), "0");
	else if (key == 38)
		put_string(param, create_color(0, 250, 250, 250), "j");
	else if (key == KEY_SPC)
		mlx_string_put(param->mlx, param->win, 25, 5, create_color(0, 250, 250, 250), "D");
	else
		printf("key = %i\n", key);
	return (0);
}

// this shit makes everything lag...
// it gets called constantly
int	event_loop(t_param *param)
{
	(void) param;
	sleep(5);
	printf("...\n");
	return (0);
}

// calls a key_hook that outputs the int corresponding to the pressed key.
int	main(void)
{
	t_param	param;

// check output of init and new_window for NULL
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 500, 500, "good little window");
	param.x = 5;
	param.y = 0;
	// these two appear to overlap perfectly. (string = [0,0], pixel = [0,6][10,12])
	// mlx_string_put(param.mlx, param.win, 0, 0, create_color(0, 0, 255, 0), "0");
	// put_pxs(&param, 0, 6, 10, 12, create_color(0, 255, 0, 0));
	put_string(&param, create_color(100, 250, 0, 0), "S");
	mlx_key_hook(param.win, event_key, (void *) &param);
	// mlx_loop_hook(param.mlx, event_loop, (void *) &param);
	mlx_loop(param.mlx);
}
