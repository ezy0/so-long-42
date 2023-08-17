/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:00:01 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/17 09:33:37 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_error(int error, t_game *game, char *aux, int no_map)
{
	int	i;

	i = 0;
	ft_error_msg(error);
	if (aux)
		free(aux);
	if (no_map)
	{
		free(game->map);
		free(game);
		exit(1);
	}
	if (game && game->map)
	{
		while (game->map[i] != NULL)
			if (game->map[i])
				free(game->map[i++]);
		free(game->map);
	}
	if (game)
		free(game);
	exit (1);
}

void	ft_error_msg(int error)
{
	if (error == 0)
		ft_printf("Error\nNo se ha podido abrir el archivo\n");
	if (error == 1)
		ft_printf("Error\nFallo de memoria\n");
	if (error == 2)
		ft_printf("Error\nEl mapa está vacío\n");
	if (error == 3)
		ft_printf("Error\nLas paredes están mal o falta una salida\n");
	if (error == 4)
		ft_printf("Error\nNo se ha encontrado la imagen\n");
	if (error == 5)
		ft_printf("Error\nEl mapa no es rectangular\n");
	if (error == 6)
		ft_printf("Error\nLos elementos del mapa son incorrectos\n");
	if (error == 7)
		ft_printf("Error\nElimina las líneas vacías del mapa\n");
}

void	ft_main_exit(t_data *data)
{
	int	i;

	i = 0;
	if (data->game && data->game->map)
	{
		while (data->game->map[i])
			free(data->game->map[i++]);
		free(data->game->map);
	}
	if (data->game)
		free(data->game);
	else
		ft_printf("Error\nFallo de memoria\n");
}

void	ft_mlx_error(t_data *data)
{
	int	i;

	i = 0;
	if (data->game)
	{
		if (data->game->map)
		{
			while (data->game->map[i] != NULL)
				free(data->game->map[i++]);
			free(data->game->map);
		}
		free(data->game);
	}
	ft_printf("Error\nFallo creando la ventana de juego\n");
}

int	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	if (data->game)
	{
		if (data->game->map)
		{
			while (data->game->map[i])
				free(data->game->map[i++]);
			free(data->game->map);
		}
		free(data->game);
	}
	if (data->mlx && data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}
