/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:13:47 by migmoren          #+#    #+#             */
/*   Updated: 2023/03/08 19:15:10 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->items = 0;
	game->moves = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->map_h = 0;
	game->map_w = 0;
}

void	map_init(t_game *game, char *map)
{
	ft_map_height(game, map);
	if (game->map_h == 0)
	{
		ft_printf("Error\nEl mapa está vacío\n");
		exit(1);
	}
}

void	data_init(t_data *data)
{
	if (!data)
		return ;
	data->mlx = mlx_init(); //Inicializacion del mlx
	//Comprobación de error??
	data->win = mlx_new_window(data->mlx, 1280, 960, "diamantes pal free"); //Abrimos nueva ventana
	//Comprobación de error?
	

	/*data.image->img = mlx_new_image(data.mlx, 1920, 1080); //Creamos una imagen
	data.image->addr = mlx_get_data_addr(data.image->img, 
			&data.image->bits_per_pixel, 
			&data.image->line_length, &data.image->endian);  //Le pasamos la direccion de la imagen
	my_mlx_pixel_put(data, 5, 5, 0x00FF0000); //Colocamos un pixel rojo en  la posicion 5 5 de la imagen
	mlx_put_image_to_window(data.mlx, data.win, data.image->img, 0, 0); //Colocamos la imagen en la pantalla*/


	mlx_loop(data->mlx);
}