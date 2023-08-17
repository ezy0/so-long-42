/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:13:47 by migmoren          #+#    #+#             */
/*   Updated: 2023/08/17 09:22:23 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->items = 0;
	game->moves = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->map_h = 0;
	game->map_w = 0;
	game->map = NULL;
}

void	map_init(t_game *game, char *map)
{
	ft_map_height(game, map);
	if (game->map_h == 0)
		ft_map_error(2, game, NULL, 0);
	ft_parse_map(game, map);
	if (!ft_validate_map(game))
		ft_map_error(3, game, NULL, 0);
}
