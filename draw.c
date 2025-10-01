#include "so_long.h"

void    draw(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.imgw, (64 * j), (64 * i));
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.imgb, (64 * j), (64 * i));
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.imgc, (64 * j), (64 * i));
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.imgp, (64 * j), (64 * i));
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.imge, (64 * j), (64 * i));
			j++;
		}
		i++;
	}
}
