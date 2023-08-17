/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:06:49 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/17 09:53:19 by migmoren         ###   ########.fr       */
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

int	ft_validate_map(t_game *game)
{
	int		len;
	int		h;

	h = 0;
	len = ft_strlen(game->map[0]);
	game->map_w = len;
	if (game->map_h == game->map_w)
		ft_map_error(5, game, NULL, 0);
	while (h < game->map_h)
	{	
		if (!game->map[h])
			ft_map_error(7, game, NULL, 0);
		if (game->map[h][0] != '1' || game->map[h][len - 1] != '1')
			ft_map_error(3, game, NULL, 0);
		h++;
	}
	if (!ft_validate_walls(game, h - 1, len))
		ft_map_error(3, game, NULL, 0);
	if (!ft_validate_elements(game, h, len))
		ft_map_error(6, game, NULL, 0);
	return (1);
}

int	ft_validate_walls(t_game *game, int h, int w)
{
	int	i;
	int	exit;
	int	aux_h;

	i = 0;
	exit = 0;
	while (i < w)
	{
		if (game->map[0][i] != '1' || game->map[h][i] != '1')
			return (0);
		aux_h = 0;
		while (++aux_h < h)
		{
			if (game->map[aux_h][i] == 'E')
				exit++;
		}
		i++;
	}
	if (exit != 1)
		return (0);
	return (1);
}

int	ft_validate_elements(t_game *game, int h, int w)
{
	int		aux_w;
	int		aux_h;
	int		player;
	char	aux;

	aux_w = 0;
	player = 0;
	while (++aux_w < w)
	{
		aux_h = 0;
		while (++aux_h < h)
		{
			aux = game->map[aux_h][aux_w];
			if (aux == 'P')
				player++;
			else if (aux == 'C')
				game->items++;
			else if (aux != '0' && aux != '1' && aux != 'E')
				return (0);
		}
	}
	if (game->items < 1 || player != 1)
		return (0);
	return (1);
}
