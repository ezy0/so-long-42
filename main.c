/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:06:47 by migmoren          #+#    #+#             */
/*   Updated: 2023/05/29 14:10:57 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	data.game = (t_game *)malloc(sizeof(t_game));
	if (!data.game)
	{
		ft_printf("Error\nFallo de memoria\n");
		ft_main_exit(&data);
		return (0);
	}
	if (argc < 2)
		ft_printf("Error\nFaltan argumentos. Prueba con ./so_long *.ber\n");
	else if (argc > 2)
		ft_printf("Error\nDemasiados argumentos. Prueba con ./so_long *.ber\n");
	else if (!ft_validate_extension(argv[1]))
		ft_printf("Error\nLa extensión del mapa es errónea, utiliza un .ber\n");
	else
	{
		game_init(data.game);
		map_init(data.game, argv[1]);
		for (int i = 0; i < data.game->map_h; i++)
			ft_printf("%s\n", data.game->map[i]);
		//data_init(&data);
		ft_mlx_game(&data);
	}
	ft_exit(&data); //¿Da errores si no se ha llegado a ccrear la ventana?
	return (0);
}
