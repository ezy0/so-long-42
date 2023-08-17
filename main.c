/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:06:47 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/17 13:37:35 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
		ft_printf("Error\nFaltan argumentos. Prueba con ./so_long *.ber\n");
	else if (argc > 2)
		ft_printf("Error\nDemasiados argumentos. Prueba con ./so_long *.ber\n");
	else if (!ft_validate_extension(argv[1]))
		ft_printf("Error\nLa extensión del mapa es errónea, utiliza un .ber\n");
	else
	{
		ft_bzero(&data, sizeof(t_data));
		data.game = (t_game *)malloc(sizeof(t_game));
		if (!data.game)
		{
			ft_main_exit(&data);
			return (0);
		}
		game_init(data.game);
		map_init(data.game, argv[1]);
		ft_mlx_game(&data);
		ft_exit(&data);
	}
	return (1);
}
