#include "so_long.h"

void	image_set(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->img.imgp = mlx_xpm_file_to_image(game->mlx_ptr, "./image/p.xpm", \
			&game->img.x, &game->img.y);
	game->img.imge = mlx_xpm_file_to_image(game->mlx_ptr, "./image/e.xpm", \
			&game->img.x, &game->img.y);
	game->img.imgc = mlx_xpm_file_to_image(game->mlx_ptr, "./image/c.xpm", \
			&game->img.x, &game->img.y);
	game->img.imgw = mlx_xpm_file_to_image(game->mlx_ptr, "./image/w.xpm", \
			&game->img.x, &game->img.y);
	game->img.imgb = mlx_xpm_file_to_image(game->mlx_ptr, "./image/b.xpm", \
			&game->img.x, &game->img.y);
}

void	map_check_set(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	game->check.visited = (int **)calloc(sizeof(int *), (game->height));
	while (game->map[i])
	{
		game->check.visited[i] = (int *)calloc(sizeof(int), (game->width));
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				game->check.visited[i][j] = 1;
			else
				game->check.visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		file_check(char **file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	return (i - 1);
}

int ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i]) {
			return (unsigned char)str1[i] - (unsigned char)str2[i];
		}
		i++;
	}
	return (unsigned char)str1[i] - (unsigned char)str2[i];
}
