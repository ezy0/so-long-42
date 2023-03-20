/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:06:47 by migmoren          #+#    #+#             */
/*   Updated: 2023/03/20 18:23:47 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int argc, char *argv[])
{
	t_data	data;
	
	data.game = (t_game *)malloc(sizeof(t_game));
	if (!data.game)
	{
		ft_printf("Error\nFallo de memoria\n");
		return (0);
	}
	else if (argc < 2)
		ft_printf("Error\nFaltan argumentos. Prueba con ./so_long (mapa).ber\n");
	else if (argc > 2)
		ft_printf("Error\nDemasiados argumentos. Prueba con ./so_long (mapa).ber\n");
	else if (!ft_validate_extension(argv[1]))
		ft_printf("Error\nLa extensión del mapa es errónea, utiliza un .ber\n");
	else
	{
		game_init(data.game);	//Inicializacion de los valores de game
		map_init(data.game, argv[1]);
		data_init(&data);
	}
	free(data.game);
	return (0);
}