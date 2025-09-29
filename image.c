#include "so_long.h"

void	map_move(t_game *game, int y, int x)
{
	char	*pt;

	if (game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
		game->map_textures.collectible--;
	if (game->map[y][x] == 'E')
	{
		if (game->map_textures.collectible == 0)
			error_exit(game, NULL, 1);
		else
			return ;
	}
	game->move++;
	game->map[game->check.y][game->check.x] = '0';
    game->check.y = y;
    game->check.x = x;
	game->map[y][x] = 'P';
	pt = ft_itoa(game->move);
	write(1, pt, ft_strlen(pt));
	free(pt);
	write(1, "\n", 1);
}

int	func(int key, t_game *game)
{
	if (key == 65307)
		error_exit(game, NULL, 1);
	if (key == 119)
		map_move(game, game->check.y - 1, game->check.x);
	else if (key == 97)
		map_move(game, game->check.y, game->check.x - 1);
	else if (key == 115)
		map_move(game, game->check.y + 1, game->check.x);
	else if (key == 100)
		map_move(game, game->check.y, game->check.x + 1);
    draw(game);
	return (0);
}

// 119 W
// 97 A
// 115 S
// 100 D