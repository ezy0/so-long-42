/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:00:01 by migmoren          #+#    #+#             */
/*   Updated: 2023/07/07 13:17:28 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_error(int error, t_game *game, char *aux)
{
	int	i;

	i = 0;
	if (error == 0)
		ft_printf("Error\nNo se ha podido abrir el archivo\n");
	if (error == 1)
		ft_printf("Error\nFallo de memoria\n");
	if (error == 2)
		ft_printf("Error\nEl mapa está vacío\n");
	if (error == 3)
		ft_printf("Error\nEl mapa es incorrecto\n");
	if (error == 4)
		ft_printf("Error\nNo se ha encontrado la imagen\n");
	if (aux != NULL)
		free(aux);
	if (game->map != NULL)
	{
		while (game->map[i] != NULL)
			free(game->map[i++]);
		free(game->map);
	}
	if (game != NULL)
		free(game);
	exit (1);
}

void	ft_main_exit(t_data *data)
{
	int	i;

	i = 0;
	if (data->game->map)
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
