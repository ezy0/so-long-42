/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:29:45 by migmoren          #+#    #+#             */
/*   Updated: 2023/07/06 20:27:59 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx.h"

/*--- ASSETS ---*/
# define BCKG_W 32
# define BCKG_H 32

# define FLOOR "assets/floor/floor.xpm"
# define WALL "assets/wall/wall.xpm"
# define CUL "assets/wall/corner_up_left.xpm"
# define CUR "assets/wall/corner_up_right.xpm"
# define LEFT "assets/wall/left.xpm"
# define RIGHT "assets/wall/right.xpm"
# define BARREL "assets/elements/barrel.xpm"
# define DOOR_C "assets/elements/door_closed.xpm"
# define DOOR_O "assets/elements/door_opened.xpm"

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
void	data_init(t_data *data);
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
void	ft_floor(char *bckg, t_data *data);
void	ft_put_img(char *img, int x, int y, t_data *data);
void	ft_draw_walls(int w, int h, char map_char, t_data *data);
void	ft_draw_elements(int w, int h, char map_char, t_data *data);

#endif