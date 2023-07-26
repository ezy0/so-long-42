/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:29:45 by migmoren          #+#    #+#             */
/*   Updated: 2023/07/26 21:10:46 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx.h"

/*.... ASSETS ....*/
# define BCKG_W 32
# define BCKG_H 32

# define FLOOR "textures/floor/floor.xpm"
# define FLOOR2 "textures/floor/floor2.xpm"
# define FLOOR3 "textures/floor/floor3.xpm"
# define FLOOR4 "textures/floor/floor4.xpm"

# define WALL "textures/wall/wall.xpm"
# define CUL "textures/wall/corner_up_left.xpm"
# define CUR "textures/wall/corner_up_right.xpm"
# define LEFT "textures/wall/left.xpm"
# define RIGHT "textures/wall/right.xpm"
# define BARREL "textures/elements/barrel.xpm"
# define DOOR_C "textures/elements/door_closed.xpm"
# define DOOR_O "textures/elements/door_opened.xpm"
# define KEY "textures/elements/key.xpm"
# define PLAYER "textures/player/player.xpm"
# define PLAYER_R "textures/player/player_right.xpm"
# define PLAYER_L "textures/player/player_left.xpm"

/*... KEYS ...*/
# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2

typedef struct s_game {
	int		player_x;
	int		player_y;
	int		moves;
	int		items;
	int		map_w;
	int		map_h;
	char	**map;
}						t_game;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*image;
	t_game	*game;
}						t_data;

void	game_init(t_game *game);
void	map_init(t_game *game, char *map);
int		ft_validate_extension(char *map);
void	ft_map_height(t_game *game, char *map);
void	ft_map_error(int error, t_game *game, char *aux);
void	ft_main_exit(t_data *data);
void	ft_parse_map(t_game *game, char *map);
int		ft_validate_map(t_game *game);
int		ft_validate_walls(t_game *game, int h, int w);
int		ft_validate_elements(t_game *game, int h, int w);
void	ft_mlx_game(t_data *data);
void	ft_mlx_error(t_data *data);
int		ft_exit(t_data *data);
void	ft_render(t_data *data);
void	ft_floor(t_data *data);
void	ft_put_img(char *img, int x, int y, t_data *data);
void	ft_draw_walls(int w, int h, char map_char, t_data *data);
void	ft_draw_elements(int w, int h, char map_char, t_data *data);
int		ft_keys(int key, t_data *data);
void	ft_movement(int x, int y, t_data *data);
void	ft_print_movements(t_data *data);
int		ft_valid_path(t_game *game);
int		ft_check_exit(int x, int y, char **map, t_game *game);
int		ft_valid_keys(t_game *game);
int		ft_check_keys(int x, int y, char **map, t_game *game);

#endif