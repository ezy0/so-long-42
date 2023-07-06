/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:06:49 by migmoren          #+#    #+#             */
/*   Updated: 2023/07/06 20:31:31 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_extension(char *map)
{
	int		len;
	char	*aux;

	if (!map)
		return (0);
	len = ft_strlen(map);
	aux = ft_substr(map, len - 4, len - 1);
	if (!map || ft_strncmp(aux, ".ber", 4))
		return (0);
	return (1);
}

int	ft_validate_map(t_game *game)//COMPROBAR CAMINO VALIDO Y LA EXISTENCIA DE LOS 5 CARACTERES, SIN REPETICION DE SALIDA E INICIO
{
	int		len;
	int		h;
	
	h = 0;
	len = ft_strlen(game->map[0]);
	game->map_w = len;
	if (game->map_h == game->map_w)
		ft_map_error(3, game ,NULL);
	while (h < game->map_h)
	{	
		if (game->map[h][0] != '1' || game->map[h][len - 1] != '1'){
			ft_map_error(3, game ,NULL);
		}
		h++;
	}
	if (!ft_validate_walls(game, h-1, len) 
		|| !ft_validate_elements(game, h, len))
		ft_map_error(3, game ,NULL);
	//Hay que chekear tambien el camino valido
	return (1);
}

int	ft_validate_walls(t_game *game, int h, int w)
{
	int	i;

	i = 0;
	while(i < w)
	{
		if (game->map[0][i] != '1' || game->map[h][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_validate_elements(t_game *game, int h, int w)
{
	int	auxW;
	int	auxH;
	int	exit;
	char aux;

	auxW = 0;
	exit = 0;
	while(++auxW < w)
	{
		auxH = 0;
		while (++auxH < h)
		{
			aux = game->map[auxH][auxW];
			if (aux == 'E')
				exit++;
			else if (aux != '0' && aux != '1')
				return (0);
		}
	}
	if (exit != 1)
		return (0);
	return (1);
}
