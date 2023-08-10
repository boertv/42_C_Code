#include "so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 500, 500, "good little window");
	mlx_loop(mlx_ptr);
}
