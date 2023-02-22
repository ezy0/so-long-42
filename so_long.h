/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:29:45 by migmoren          #+#    #+#             */
/*   Updated: 2023/02/22 20:16:19 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include "mlx_opengl/mlx.h"

void	game_init(t_game game);

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
	void	*img; //Puntero a la imagen actual
	t_game	*game; //Puntero al resto de información del juego
}						t_data;

#endif