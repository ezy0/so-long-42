/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:29:45 by migmoren          #+#    #+#             */
/*   Updated: 2023/03/20 18:50:03 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_game {
	int		player_x; //Posiciones del jugador
	int		player_y;
	int		moves; //Contador de movimientos
	int		items; //Contador de coleccionables recogidos
	int		map_w; //Anchura del mapa
	int		map_h; //Altura del mapa
	char	**map; //Mapa
}						t_game;

typedef struct s_data {
	void	*mlx; //Puntero conectado a la libreria grafica
	void	*win; //Puntero a la ventana actual
	void	*image; //Puntero a la imagen actual
	t_game	*game; //Puntero al resto de información del juego
}						t_data;


void	game_init(t_game *game);
void	data_init(t_data *data);
void	map_init(t_game *game, char *map);
int 	ft_validate_extension(char *map);
void	ft_map_height(t_game *game, char *map);
void	ft_map_error(int error, t_game *game, char *aux);
void	ft_parse_map(t_game *game, char *map);

#endif