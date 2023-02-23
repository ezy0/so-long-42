/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:06:47 by migmoren          #+#    #+#             */
/*   Updated: 2023/02/23 19:40:03 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int argc, char *argv[])
{
	t_data	data;
	
	data.game = malloc(sizeof(t_game));
	if (!data.game)
		return (0);
		/*ft_printf("Error\nFallo de memoria\n");
	if (argc < 2)
		ft_printf("Error, faltan argumentos. Prueba con ./so_long (mapa).ber\n");
	if (argc > 2)
		ft_printf("Error, demasiados argumentos. Prueba con ./so_long (mapa).ber\n");
	else
	{

	}*/

	game_init(data.game);
	screen_init(data);

	return (0);
}