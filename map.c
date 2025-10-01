#include "so_long.h"

char	*read_map(t_game *game, char *argv)
{
	int		fd;
	char	*temp;
	char	*line;
	char	*free_temp;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit(game);
	temp = NULL;
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free_temp = temp;
		temp = ft_strjoin(free_temp, line);
		free(free_temp);
		if (temp != line)
			free(line);
		game->height++;
	}
	close(fd);
	return (temp);
}

char	*check_map(char *temp, t_game *game)
{
	int		i;

	i = -1;
	if (temp == NULL)
		return (NULL);
	while (temp[++i])
	{
		if (temp[i] == 'P')
		{
			game->map_textures.player++;
			game->map_textures.index = i;
		}
		else if (temp[i] == 'C')
			game->map_textures.collectible++;
		else if (temp[i] == 'E')
			game->map_textures.exit++;
		else if (temp[i] == '1' || temp[i] == '0' || temp[i] == '\n')
			;
		// else
		// 	error_exit(game, temp, 0);
	}
	if (game->map_textures.player != 1 || game->map_textures.exit != 1 || game->map_textures.collectible < 1)
		error_exit(game, NULL, 0);
	return (temp);
}

void	width_check(t_game *game, char *argv)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_exit(game);
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (game->width == 0)
			game->width = strlen(line) - 1;
		if (line[strlen(line) - 1] == '\n')
			len = strlen(line) - 1;
		if (line[strlen(line) - 1] == '\0')
			len = strlen(line);
		if (game->width != len)
		{
			close(fd);
			error_exit(game, line, 0);
		}
		free(line);
	}
	close(fd);
}

// void	map_wall(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while(game->map[i][j])
// 		{
// 			if (game->map[0][j] != '1')
// 				error_exit(game, NULL, 0);
// 			if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
// 				error_exit(game, NULL, 0);
// 			if (game->map[game->height - 1][j] != '1')
// 				error_exit(game, NULL, 0);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	map_dfs(t_game *game, int x, int y, int **visited)
{
	if (visited[y][x] == 1)
		return ;
	if (visited[y][x] == 0)
	{
		if (game->map[y][x] == 'E')
			game->map_textures.exit--;
		else if (game->map[y][x] == 'C')
			game->map_textures.collectible--;
		visited[y][x] = 1;
	}
	map_dfs(game, x + 1, y, visited);
	map_dfs(game, x - 1, y, visited);
	map_dfs(game, x, y + 1, visited);
	map_dfs(game, x, y - 1, visited);
}

void	map(t_game *game, char *argv)
{
	int	exit_count;
	int	collectible_count;
	char	*free_str;

	width_check(game, argv);
	free_str = check_map(read_map(game, argv), game);
	game->map = ft_split(free_str, '\n');
	free(free_str);
	map_check_set(game);
//	map_wall(game);
	game->check.y = game->map_textures.index / (game->width + 1);
	game->check.x = game->map_textures.index % (game->width + 1);
	exit_count = game->map_textures.exit;
	collectible_count = game->map_textures.collectible;
	map_dfs(game, game->check.x, game->check.y, game->check.visited);
    if (game->map_textures.exit != 0 || game->map_textures.collectible != 0)
		error_exit(game, NULL, 0);
	game->map_textures.exit = exit_count;
	game->map_textures.collectible = collectible_count;
    image_set(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->img.x * game->width, game->img.y * game->height, "SO____LONG");
}
