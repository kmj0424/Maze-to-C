/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim2 <minkim2@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-08 09:37:35 by minkim2           #+#    #+#             */
/*   Updated: 2025-03-08 09:37:35 by minkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_int(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->check.visited[i]);
		i++;
	}
	free(game->check.visited);
}

void	free_char(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	error_exit(t_game *game, char *temp, int i)
{
	if (game->map)
		free_char(game->map);
	if (game->check.visited)
		free_int(game);
	if (temp != NULL)
		free(temp);
	if (i == 1)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.imgb);
		mlx_destroy_image(game->mlx_ptr, game->img.imgp);
		mlx_destroy_image(game->mlx_ptr, game->img.imgc);
		mlx_destroy_image(game->mlx_ptr, game->img.imge);
		mlx_destroy_image(game->mlx_ptr, game->img.imgw);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(0);
	}
	if (i > 2)
		close(i);
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_exit(t_game *game)
{
	if (game->map)
		free_char(game->map);
	if (game->check.visited)
		free_int(game);
	mlx_destroy_image(game->mlx_ptr, game->img.imgb);
	mlx_destroy_image(game->mlx_ptr, game->img.imgp);
	mlx_destroy_image(game->mlx_ptr, game->img.imgc);
	mlx_destroy_image(game->mlx_ptr, game->img.imge);
	mlx_destroy_image(game->mlx_ptr, game->img.imgw);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	printf("In Close\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	// char	**file;
	// int		file_len;

	// if (argc != 2)
	// {
	// 	write(1, "Error\n", 6);
	// 	return (1);
	// }
	// file = ft_split(argv[1], '/');
	// file_len = file_check(file);
	// if ((strcmp(strrchr(file[file_len], '.'), ".ber") != 0) \
	// 		|| strlen(file[file_len]) < 5)
	// {
	// 	free_char(file);
	// 	write(1, "Error\n", 6);
	// 	return (1);
	// }
	// free_char(file);
	int i;
	printf("(1)easy, (2) normal, (3)hard\n");
	scanf("%d", &i);
	if (i == 1)
		argv[1] = "./map/easy.ber";
	else if (i == 2)
		argv[1] = "./map/normal.ber";
	else
		argv[1] = "./map/hard.ber";
	memset(&game, 0, sizeof(t_game));
	map(&game, argv[1]);
	draw(&game);
	mlx_key_hook(game.win_ptr, func, &game);
	mlx_hook(game.win_ptr, X_EVENT_KEYPRESS, 0L, ft_exit, &game);
	mlx_hook(game.win_ptr, X_EVENT_EXIT, 0L, ft_exit, &game);
	mlx_loop(game.mlx_ptr);
}
