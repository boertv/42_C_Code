#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_param
{
	void	*mlx;
	void	*win;
}			t_param;

int	event_key(int key, t_param *param)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit (0);
	}
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
	mlx_key_hook(param.win, event_key, (void *) &param);
	// mlx_loop_hook(param.mlx, event_loop, (void *) &param);
	mlx_loop(param.mlx);
}
