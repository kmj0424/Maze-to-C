/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim2 <minkim2@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-08 06:01:50 by minkim2           #+#    #+#             */
/*   Updated: 2025-03-08 06:01:50 by minkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include "./mlx/mlx.h"
# include <stdio.h>

# define TILES 64
# define X_EVENT_KEYPRESS 2
# define X_EVENT_EXIT 17

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_map
{
	int	wall;
	int	player;
	int	collectible;
	int	exit;
	int	index;
}		t_map;

typedef struct s_check
{
	int	y;
	int	x;
	int	collectible;
	int	**visited;
}	t_check;

typedef struct s_img
{
	void	*imgp;
	void	*imge;
	void	*imgc;
	void	*imgw;
	void	*imgb;
	int		x;
	int		y;
}	t_img;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	int			collected;
	int			move;
	t_img		img;
	t_map		map_textures;
	char		**map;
	int			valid_path;
	t_check		check;
}	t_game;

void	map_move(t_game *game, int y, int x);
int		func(int key, t_game *game);

void	draw(t_game *game);

void	image_set(t_game *game);
void	map_check_set(t_game *game);

void	error_exit(t_game *game, char *temp, int i);
int		ft_exit(t_game *game);

int		file_check(char **file);
int ft_strcmp(char *str1, char *str2);

char	*read_map(t_game *game, char *argv);
char	*check_map(char *temp, t_game *game);
void	width_check(t_game *game, char *argv);
void	map_wall(t_game *game);
void	map_dfs(t_game *game, int x, int y, int **visited);
void	map(t_game *game, char *argv);

char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

#endif
