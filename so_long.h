/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:29:45 by migmoren          #+#    #+#             */
/*   Updated: 2023/05/29 13:59:26 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

/*--- ASSETS ---*/
# define  BCKG_W 64
# define  BCKG_H 48

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
void	ft_mlx_game(t_data *data);
void	ft_mlx_error(t_data *data);
int		ft_exit(t_data *data);
void	ft_render(t_data *data);

#endif