/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:13:46 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/17 11:34:27 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_aux(char **map_aux, t_game *game)
{
	int	i;

	i = -1;
	if (!map_aux)
		return ;
	while (++i < game->map_h)
		free(map_aux[i]);
	free(map_aux);
}

int	ft_valid_path(t_game *game)
{
	int		y;
	char	**map_aux;

	y = -1;
	map_aux = (char **)malloc(sizeof(char *) * game->map_h + 1);
	if (!map_aux)
		return (0);
	while (++y < game->map_h)
		map_aux[y] = ft_strdup(game->map[y]);
	y = -1;
	if (ft_check_exit(game->player_x, game->player_y, map_aux, game) > 0)
	{
		while (++y < game->map_h)
			free(map_aux[y]);
		free(map_aux);
		return (1);
	}
	ft_free_aux(map_aux, game);
	return (0);
}

int	ft_check_exit(int x, int y, char **map, t_game *game)
{
	int	result;
	int	aux;

	result = 0;
	aux = -1;
	while (++aux < game->map_h)
		if (!map[aux])
			return (-1);
	if (x < 0 || x >= game->map_w || y < 0 || y >= game->map_h
		|| map[y][x] == '1')
		return (result);
	if (map[y][x] == 'E')
		result++;
	map[y][x] = '1';
	result += ft_check_exit(x + 1, y, map, game);
	result += ft_check_exit(x - 1, y, map, game);
	result += ft_check_exit(x, y + 1, map, game);
	result += ft_check_exit(x, y - 1, map, game);
	return (result);
}

int	ft_valid_keys(t_game *game)
{
	int		y;
	char	**map_aux;

	y = -1;
	map_aux = (char **)malloc(sizeof(char *) * game->map_h + 1);
	if (!map_aux)
		return (0);
	while (++y < game->map_h)
		map_aux[y] = ft_strdup(game->map[y]);
	y = -1;
	if (ft_check_keys(game->player_x, game->player_y, map_aux
			, game) == game->items)
	{
		while (++y < game->map_h)
			free(map_aux[y]);
		free(map_aux);
		return (1);
	}
	ft_free_aux(map_aux, game);
	return (0);
}

int	ft_check_keys(int x, int y, char **map, t_game *game)
{
	int	keys;
	int	aux;

	aux = -1;
	keys = 0;
	while (++aux < game->map_h)
		if (!map[aux])
			return (-1);
	if (x < 0 || x >= game->map_w || y < 0 || y >= game->map_h
		|| map[y][x] == '1' || map[y][x] == 'E')
		return (keys);
	if (map[y][x] == 'C')
		keys++;
	map[y][x] = '1';
	keys += ft_check_keys(x + 1, y, map, game);
	keys += ft_check_keys(x - 1, y, map, game);
	keys += ft_check_keys(x, y + 1, map, game);
	keys += ft_check_keys(x, y - 1, map, game);
	return (keys);
}
