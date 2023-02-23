/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:29:45 by migmoren          #+#    #+#             */
/*   Updated: 2023/02/23 19:50:33 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <unistd.h>
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

typedef struct s_img {
	void	*img;	//Ptr a la imagen
	char	*addr;	//Ptr a la direccion de memoria
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}						t_img;

typedef struct s_data {
	void	*mlx; //Puntero conectado a la libreria grafica
	void	*win; //Puntero a la ventana actual
	t_img	*image; //Puntero a la imagen actual
	t_game	*game; //Puntero al resto de información del juego
}						t_data;


void	game_init(t_game *game);
void	screen_init(t_data data);
void	my_mlx_pixel_put(t_data data, int x, int y, int color);


#endif