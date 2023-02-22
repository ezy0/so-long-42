/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:06:47 by migmoren          #+#    #+#             */
/*   Updated: 2023/02/22 20:14:23 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int argc, char *argv[])
{
	t_data	*data;
	
	if (argc < 2)
		ft_printf("Error, faltan argumentos. Prueba con ./so_long (mapa).ber\n");
	if (argc > 2)
		ft_printf("Error, demasiados argumentos. Prueba con ./so_long (mapa).ber\n");
	else
	{
		game_init(data->game);
	}
	return (0);
}